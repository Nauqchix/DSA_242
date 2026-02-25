#include "../unit_test_hash.hpp"

bool UNIT_TEST_Hash::hash23() {
  string name = "hash23";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.5);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect =
      "0\n\
[1, 2, 3, 51, 31, 11, 61, 41, 21]\n\
[votien_1, votien2, votien3, votien51, votien31, votien11, votien61, votien41, votien21]\n\
[0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1]";

  //! output ----------------------------------
  stringstream output;
  output << hash.empty() << endl;
  output << hash.keys().toString() << endl;
  output << hash.values().toString() << endl;
  output << hash.clashes().toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
