#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap25() {
  string name = "heap25";
  //! data ------------------------------------
  int array[] = {1, 4, 2};
  Heap<int> heap;
  heap.heapify(array, 3);

  //! expect ----------------------------------
  string expect = "size=3;empty=0;[1,4,2]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
