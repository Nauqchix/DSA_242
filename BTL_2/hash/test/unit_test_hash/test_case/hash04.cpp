#include "../unit_test_hash.hpp"

bool UNIT_TEST_Hash::hash04() {
  string name = "hash04";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash);
  hash.put(1, "votien1");
  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       1\n\
0   : \n\
1   :  (1,votien1)\n\
2   : \n\
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
