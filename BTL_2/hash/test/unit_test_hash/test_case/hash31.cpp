#include "../unit_test_hash.hpp"

bool UNIT_TEST_Hash::hash31() {
  string name = "hash31";
    int keys[] = {2, 12, 42, 72, 3, 45, 76, 30};
    int values[] = {35, 67, 100, 23, 68, 68, 72, 45};

    xMap<int, int> map(&hashFunc);
    for (int idx = 0; idx < 6; idx++) {
        map.put(keys[idx], values[idx]);
    }
    stringstream output;
    output<<map.toString();
    DLinkedList<int> list = map.clashes();
   output<< list.toString();
    string expect ="==================================================\n\
capacity:   10\n\
size:       6\n\
0   : \n\
1   : \n\
2   :  (2,35); (12,67); (42,100); (72,23)\n\
3   :  (3,68)\n\
4   : \n\
5   :  (45,68)\n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n[0, 0, 4, 1, 0, 1, 0, 0, 0, 0]";
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
