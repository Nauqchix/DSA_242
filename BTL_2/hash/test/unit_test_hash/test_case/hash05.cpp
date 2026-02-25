#include "../unit_test_hash.hpp"

bool UNIT_TEST_Hash::hash05() {
  string name = "hash05";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(2, "votien2");
  hash.put(10, "votien10");

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       5\n\
0   :  (10,votien10)\n\
1   :  (1,votien1); (11,votien11); (21,votien21)\n\
2   :  (2,votien2)\n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n" << hash.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
