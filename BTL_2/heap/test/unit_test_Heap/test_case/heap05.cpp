#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap05() {
  string name = "heap05";
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.push(7);
  heap.push(3);
  heap.push(9);
  heap.push(10);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(12);
  heap.push(11);
  heap.push(14);
  heap.push(13);
  heap.push(15);
  //! expect ----------------------------------
  string expect = "size=15;empty=0;[1,3,2,6,4,9,10,7,8,5,12,11,14,13,15]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
