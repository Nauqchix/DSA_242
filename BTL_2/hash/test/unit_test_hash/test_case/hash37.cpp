#include "../unit_test_hash.hpp"

bool UNIT_TEST_Hash::hash37() {
  string name = "hash37";
  int count = 8;
  int keys[] = {2, 12, 42, 72, 3, 45, 76, 30};
  int values[] = {35, 67, 100, 23, 68, 68, 72, 45};
  xMap<int, int*> hash(&xMap<int, int*>::simpleHash);
  for (int idx = 0; idx < count; idx++) {
      hash.put(keys[idx], 0);
  }
  //hash.println();

  DLinkedList<int> clashes = hash.clashes();
  int max = -1;
  for (DLinkedList<int>::Iterator it = clashes.begin(); it != clashes.end(); it++) {
      int item = *it;
      if (item > max) max = item;
  }
  stringstream output;
  output << "table size: " << hash.getCapacity() << endl;
  output << "current count: " << hash.size() << endl;
  output << "real load factor: " << (float) hash.size() / hash.getCapacity() << endl;
  output << "max #collisions: " << max << endl;
    string expect ="table size: 15\n\
current count: 8\n\
real load factor: 0.533333\n\
max #collisions: 3\n";
  return printResult(output.str(), expect, name);
}
