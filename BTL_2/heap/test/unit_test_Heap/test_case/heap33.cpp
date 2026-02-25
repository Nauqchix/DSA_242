#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap33() {
  string name = "heap33";
  int array[] = {50, 20, 15, 10, 8, 6, 7, 23}; 
     //min heap: [6, 10, 7, 23, 15, 20, 8, 50]
     //max heap: [50, 23, 15, 20, 8, 6, 7, 10]
     stringstream output;
     Heap<int> minHeap1;
     output << "Min Heap: ";
     minHeap1.heapify(array, 8);
     output << minHeap1.toString() << endl;
     
     Heap<int> minHeap2(minHeapComparator);
     output << "Min Heap: ";
     minHeap2.heapify(array, 8);
     output << minHeap2.toString() << endl;
     
     Heap<int> maxHeap(maxHeapComparator);
     output << "Max Heap: ";
     maxHeap.heapify(array, 8);
     output << maxHeap.toString() << endl;
    string expect ="Min Heap: [6,10,7,23,15,20,8,50]\n\
Min Heap: [6,10,7,23,15,20,8,50]\n\
Max Heap: [50,23,15,20,8,6,7,10]\n";
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
