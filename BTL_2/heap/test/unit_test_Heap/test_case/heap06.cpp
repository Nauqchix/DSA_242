#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap06() {
  string name = "heap06";
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);

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
