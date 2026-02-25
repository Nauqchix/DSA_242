#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap01() {
  string name = "heap01";
  //! data ------------------------------------
  Heap<int> heap;

  //! expect ----------------------------------
  string expect = "size=0;empty=1;[]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
