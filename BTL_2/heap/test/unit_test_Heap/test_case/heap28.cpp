#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap28() {
  string name = "heap28";
  //! data ------------------------------------
  int* array[] = {new int(15), new int(3),  new int(8),  new int(1),
                  new int(20), new int(9),  new int(4),  new int(5),
                  new int(12), new int(6),  new int(11), new int(10),
                  new int(7),  new int(14), new int(2),  new int(13),
                  new int(17), new int(18), new int(19), new int(16)};
  Heap<int*> heap(maxHeapComparator, Heap<int*>::free);
  heap.heapify(array, 20);

  //! expect ----------------------------------
  string expect =
      "size=20;empty=0;[20,19,14,18,16,9,10,13,17,11,6,8,7,4,2,1,12,5,15,3]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
