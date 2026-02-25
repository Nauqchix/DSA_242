#include "../unit_test_hash.hpp"

bool UNIT_TEST_Hash::hash08() {
  string name = "hash08";
  stringstream output;
  //! data ------------------------------------
  xMap<int*, string> hash(&newINT_keyHash, 1, 0, xMap<int*, string>::freeKey,
                          &newINT_EQ);
  int *key, *value;
  string s;

  hash.put(new int(1), "votien1");
  hash.put(new int(11), "votien11");
  hash.put(new int(3), "votien3");

  key = new int(1);
  output << hash.put(key, "votien_1");
  delete key;

  hash.put(new int(21), "votien21");
  hash.put(new int(31), "votien31");
  hash.put(new int(41), "votien41");
  hash.put(new int(51), "votien51");

  key = new int(11);
  output << hash.put(key, "votien_11");
  delete key;

  xMap<int*, string> copy(&newINT_keyHash);
  copy = hash;

  //! expect ----------------------------------
  string expect =
      "votien1votien11\n\
==================================================\n\
capacity:   10\n\
size:       7\n\
0   : \n\
1   :  (n_1,votien_1); (n_11,votien_11); (n_21,votien21); (n_31,votien31); (n_41,votien41); (n_51,votien51)\n\
2   : \n\
3   :  (n_3,votien3)\n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  output << "\n" << copy.toString(&newINT_toString);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
