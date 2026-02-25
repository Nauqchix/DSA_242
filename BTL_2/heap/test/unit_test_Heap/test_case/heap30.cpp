#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap30() {
  string name = "heap30";
  //! data ------------------------------------
  int* array[] = {new int(15), new int(3),  new int(8),  new int(1),
                  new int(20), new int(9),  new int(4),  new int(5),
                  new int(12), new int(6),  new int(11), new int(10),
                  new int(7),  new int(14), new int(2),  new int(13),
                  new int(17), new int(18), new int(19), new int(16)};
  Heap<int*> heap(minHeapComparator, Heap<int*>::free);
  heap.heapify(array, 20);

  //! expect ----------------------------------
  string expect =
      "size=20;empty=0;[1,3,2,5,6,7,4,13,12,16,11,10,9,14,8,15,17,18,19,20]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
