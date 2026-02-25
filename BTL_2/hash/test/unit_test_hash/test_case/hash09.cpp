#include "../unit_test_hash.hpp"

bool UNIT_TEST_Hash::hash09() {
  string name = "hash09";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
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
      "\n\
==================================================\n\
capacity:   15\n\
size:       9\n\
0   : \n\
1   :  (1,votien_1); (31,votien31); (61,votien61)\n\
2   :  (2,votien2)\n\
3   :  (3,votien3)\n\
4   : \n\
5   : \n\
6   :  (21,votien21); (51,votien51)\n\
7   : \n\
8   : \n\
9   : \n\
10  : \n\
11  :  (11,votien11); (41,votien41)\n\
12  : \n\
13  : \n\
14  : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n" << hash.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
