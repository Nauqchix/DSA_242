#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap10() {
  string name = "heap10";
  //! data ------------------------------------
  Heap<int> heap;

  //! expect ----------------------------------
  string expect = "Caught exception: Calling to peek with the empty heap.";

  //! output ----------------------------------
  stringstream output;
  try {
    output << heap.peek();
  } catch (const underflow_error& e) {
    output << "Caught exception: " << e.what();
  }

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
