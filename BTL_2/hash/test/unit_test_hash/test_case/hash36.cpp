#include "../unit_test_hash.hpp"

bool UNIT_TEST_Hash::hash36() {
  string name = "hash36";
  int keys[] = {2, 12, 42, 72, 3, 45, 76, 30};
  int values[] = {35, 67, 100, 23, 68, 68, 72, 45};
  xMap<int, int> hash(&xMap<int, int>::simpleHash);
  for (int idx = 0; idx < 8; idx++) {
      hash.put(keys[idx], values[idx]);
  }
  stringstream output;
  DLinkedList<int> keyset = hash.keys();
  output << "Keys: " << keyset.toString() << endl;
  DLinkedList<int> valueset = hash.values();
  output << "Values: " << valueset.toString() << endl;
    string expect ="Keys: [30, 45, 76, 2, 3, 12, 42, 72]\n\
Values: [45, 68, 72, 35, 68, 67, 100, 23]\n";
  return printResult(output.str(), expect, name);
}
