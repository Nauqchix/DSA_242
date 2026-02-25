#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap24() {
  string name = "heap24";
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
  string expect = "1 4 2 7 6 14 11 13 18 12 10 15 ";

  //! output ----------------------------------
  stringstream output;
  int index = 0;
  for (auto i = heap.begin(); i != heap.end(); ++i) {
    if (index % 2) i.remove(deleteInt);
    output << **i << " ";
    index += 1;
  }

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
