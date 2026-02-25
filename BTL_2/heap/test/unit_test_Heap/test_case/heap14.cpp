#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap14() {
  string name = "heap14";
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);

  //! expect ----------------------------------
  string expect = "True\nsize=3;empty=0;[1,4,2]";

  //! output ----------------------------------
  stringstream output;
  output << (heap.contains(2) ? "True" : "False") << endl;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
