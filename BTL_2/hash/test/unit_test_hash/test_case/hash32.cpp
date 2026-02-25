#include "../unit_test_hash.hpp"

bool UNIT_TEST_Hash::hash32() {
  string name = "hash32";
  int keys[] = {2, 12, 42, 72, 3, 45, 76, 30};
  int values[] = {35, 67, 100, 23, 68, 68, 72, 45};
  xMap<int, int> hash(&xMap<int, int>::simpleHash);
  stringstream output;
  for (int idx = 0; idx < 8; idx++) {
      hash.put(keys[idx], values[idx]);
  }
  output<<hash.toString();
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
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
