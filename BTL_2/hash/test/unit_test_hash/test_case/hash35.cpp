#include "../unit_test_hash.hpp"

bool UNIT_TEST_Hash::hash35() {
  string name = "hash35";
  int keys[] = {2, 12, 42, 72, 3, 45, 76, 30};
  Point * values[] = {
      new Point(2.3, 4.5), new Point(4.2, 6.7),
      new Point(5.2, 7.2), new Point(9.1, 1.8),
      new Point(8.9, 9.1), new Point(8.1, 3.1),
      new Point(3.3, 5.4), new Point(7.3, 4.2)
  };

  xMap<int*, Point*> hashMap(
          &hashFunc,
          0.75,
          &Point::pointEQ,
          &xMap<int*, Point*>::freeValue,
          &keyEQ,
          &xMap<int*, Point*>::freeKey
          );
  for (int idx = 0; idx < 8; idx++) {
      hashMap.put(new int(keys[idx]), values[idx]);
  }
  stringstream output;
  output<<hashMap.toString(&key2str, &point2str);
    string expect ="==================================================\n\
capacity:   15\n\
size:       8\n\
0   :  (30,(7.3, 4.2)); (45,(8.1, 3.1))\n\
1   :  (76,(3.3, 5.4))\n\
2   :  (2,(2.3, 4.5))\n\
3   :  (3,(8.9, 9.1))\n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
10  : \n\
11  : \n\
12  :  (12,(4.2, 6.7)); (42,(5.2, 7.2)); (72,(9.1, 1.8))\n\
13  : \n\
14  : \n\
==================================================\n";
  return printResult(output.str(), expect, name);
}
