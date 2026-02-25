#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap08() {
  string name = "heap08";
  stringstream output;
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  output << heap.pop() << endl;

  //! expect ----------------------------------
  string expect =
      "4\n\
size=0;empty=1;[]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
