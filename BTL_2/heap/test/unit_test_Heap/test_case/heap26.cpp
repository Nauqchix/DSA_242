#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap26() {
  string name = "heap26";
  //! data ------------------------------------
  int array[] = {15, 3,  8, 1,  20, 9,  4,  5,  12, 6,
                 11, 10, 7, 14, 2,  13, 17, 18, 19, 16};
  Heap<int> heap;
  heap.heapify(array, 20);

  //! expect ----------------------------------
  string expect =
      "size=20;empty=0;[1,3,2,5,6,7,4,13,12,16,11,10,9,14,8,15,17,18,19,20]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
