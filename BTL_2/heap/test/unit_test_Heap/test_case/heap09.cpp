#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap09() {
  string name = "heap09";
  stringstream output;
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

  output << heap.pop() << heap.pop() << heap.pop() << endl;

  //! expect ----------------------------------
  string expect =
      "123\n\
size=12;empty=0;[4,5,9,6,12,11,10,7,8,13,14,15]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
