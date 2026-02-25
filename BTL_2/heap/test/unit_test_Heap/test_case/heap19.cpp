#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap19() {
  string name = "heap19";
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

  //! expect ----------------------------------
  string expect =
      "18\nsize=17;empty=0;[17,16,14,15,7,12,13,10,5,3,4,1,9,8,11,2,6]";

  //! output ----------------------------------

  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
