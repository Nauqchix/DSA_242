#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap20() {
  string name = "heap20";
  stringstream output;
  //! data ------------------------------------
  Heap<int*> heap(maxHeapComparator, Heap<int*>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));
  heap.push(new int(8));
  heap.push(new int(6));
  heap.push(new int(9));
  heap.push(new int(12));
  heap.push(new int(7));
  heap.push(new int(5));
  heap.push(new int(3));
  heap.push(new int(10));
  heap.push(new int(14));
  heap.push(new int(15));
  heap.push(new int(11));
  heap.push(new int(13));
  heap.push(new int(16));
  heap.push(new int(18));
  heap.push(new int(17));

  int* a = heap.pop();
  output << *a << endl;
  delete a;
  a = heap.pop();
  output << *a << endl;
  delete a;
  heap.clear();

  //! expect ----------------------------------
  string expect = "18\n17\nsize=0;empty=1;[]";

  //! output ----------------------------------

  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
