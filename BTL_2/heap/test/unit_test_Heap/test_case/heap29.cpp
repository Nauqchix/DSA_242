#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap29() {
  string name = "heap29";
  //! data ------------------------------------
  int* array[] = {};
  Heap<int*> heap(maxHeapComparator, Heap<int*>::free);
  heap.heapify(array, 0);

  //! expect ----------------------------------
  string expect = "size=0;empty=1;[]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
