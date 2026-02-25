#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap22() {
  string name = "heap22";
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
  int* value = new int(15);
  heap.push(value);
  heap.push(new int(11));
  heap.push(new int(13));
  heap.push(new int(16));
  heap.push(new int(18));
  heap.push(new int(17));

  heap.remove(value, deleteInt);

  //! expect ----------------------------------
  string expect = "size=17;empty=0;[1,3,2,5,4,9,11,8,7,6,10,14,17,12,13,16,18]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
