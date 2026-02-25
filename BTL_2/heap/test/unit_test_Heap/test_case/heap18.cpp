#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap18() {
  string name = "heap18";
  //! data ------------------------------------
  Heap<int*> heap(maxHeapComparator, Heap<int*>::free);
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

  Heap<int*> copy;
  copy = heap;

  //! expect ----------------------------------
  string expect =
      "size=18;empty=0;[18,17,14,16,7,12,13,10,15,3,4,1,9,8,11,2,6,5]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << copy.size() << ";empty=" << copy.empty() << ";"
         << copy.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
