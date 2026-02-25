#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap02() {
  string name = "heap02";
  //! data ------------------------------------
  Heap<int> heap;
  Heap<int> copy(heap);

  //! expect ----------------------------------
  string expect = "size=0;empty=1;[]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << copy.size() << ";empty=" << copy.empty() << ";"
         << copy.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
