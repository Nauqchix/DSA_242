#include "../unit_test_hash.hpp"

bool UNIT_TEST_Hash::hash27() {
  string name = "hash27";
  //! data ------------------------------------
  xMap<int*, int*> hash(&newINT_keyHash, 1, &newINT_EQ,
                        xMap<int*, int*>::freeKey, &newINT_EQ,
                        xMap<int*, int*>::freeValue);
  int* key1 = new int(1);
  int* key11 = new int(11);
  int* key21 = new int(21);
  int* key31 = new int(31);
  int* key41 = new int(41);
  int* key51 = new int(51);
  int* key61 = new int(61);
  int* key2 = new int(2);
  int* key3 = new int(1);

  int* value1 = new int(100);
  int* value11 = new int(200);
  int* value21 = new int(300);
  int* value31 = new int(400);
  int* value41 = new int(500);
  int* value51 = new int(600);
  int* value61 = new int(700);
  int* value2 = new int(800);
  int* value3 = new int(900);

  hash.put(key1, value1);
  hash.put(key11, value11);
  hash.put(key21, value21);
  hash.put(key31, value31);
  hash.put(key41, value41);
  hash.put(key51, value51);
  hash.put(key61, value61);
  hash.put(key2, value2);
  hash.put(key3, value3);

  hash.remove(key61, &newINT_delete);
  hash.remove(key31, value31, &newINT_delete, &newINT_delete);

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       6\n\
0   : \n\
1   :  (n_1,n_900); (n_11,n_200); (n_21,n_300); (n_41,n_500); (n_51,n_600)\n\
2   :  (n_2,n_800)\n\
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
  output << "\n" << hash.toString(&newINT_toString, &newINT_toString);

  //! remove data -----------------------------
  delete value1;
  delete key3;
  delete value61;

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
