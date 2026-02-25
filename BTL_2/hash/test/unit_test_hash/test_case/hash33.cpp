#include "../unit_test_hash.hpp"

bool UNIT_TEST_Hash::hash33() {
  string name = "hash33";
  int keys[] = {2, 12, 42, 72, 3, 45, 76, 30};
  int values[] = {35, 67, 100, 23, 68, 68, 72, 45};
  stringstream output;
  xMap<int, int*> hashMap(
          &xMap<int, int*>::simpleHash,
          0.75,
          &valueEQ,
          &xMap<int, int*>::freeValue,
          0, //keyEQ
          0 //deleteKeys
          );
  for (int idx = 0; idx < 8; idx++) {
      hashMap.put(keys[idx], new int(values[idx]));
  }
  string expect ="==================================================\n\
capacity:   15\n\
size:       8\n\
0   :  (30,45); (45,68)\n\
1   :  (76,72)\n\
2   :  (2,35)\n\
3   :  (3,68)\n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
10  : \n\
11  : \n\
12  :  (12,67); (42,100); (72,23)\n\
13  : \n\
14  : \n\
==================================================\n";
 output<< hashMap.toString(0, &value2str);
  return printResult(output.str(), expect, name);
}
