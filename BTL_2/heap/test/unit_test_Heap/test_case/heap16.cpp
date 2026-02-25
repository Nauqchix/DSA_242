#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap16() {
  string name = "heap16";
  //! data ------------------------------------
  Heap<int*> heap(maxHeapComparator, Heap<int*>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));

  //! expect ----------------------------------
  string expect = "size=3;empty=0;[4,2,1]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
