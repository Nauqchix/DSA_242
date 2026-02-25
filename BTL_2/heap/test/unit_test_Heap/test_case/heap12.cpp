#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap12() {
  string name = "heap12";
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.remove(2);

  //! expect ----------------------------------
  string expect = "size=2;empty=0;[1,4]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
