#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap23() {
  string name = "heap23";
  //! data ------------------------------------
  Heap<int*> heap(minHeapComparator, Heap<int*>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));
  heap.push(new int(8));
  heap.push(new int(6));
  heap.push(new int(9));
  heap.push(new int(12));
  heap.push(new int(7));
  heap.push(new int(5));
  heap.push(new int(3));
  heap.push(new int(10));
  heap.push(new int(14));
  heap.push(new int(15));
  heap.push(new int(11));
  heap.push(new int(13));
  heap.push(new int(16));
  heap.push(new int(18));
  heap.push(new int(17));

  //! expect ----------------------------------
  string expect = "1 3 2 5 4 9 11 8 7 6 10 14 15 12 13 16 18 17 ";

  //! output ----------------------------------
  stringstream output;
  for (auto i : heap) {
    output << *i << " ";
  }

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
