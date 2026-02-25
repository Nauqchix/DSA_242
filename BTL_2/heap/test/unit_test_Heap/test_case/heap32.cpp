#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap32() {
  string name = "heap32";
  int array[] = {50, 20, 15, 10, 8, 6, 7, 23}; 
               //    0   1   2   3  4  5  6   7
     //min heap: [6, 10, 7, 23, 15, 20, 8, 50]
     //[6,10,7,23,15,20,8,50]
     stringstream output;
     output << "Input array: ";
     for(int idx =0; idx < 8; idx++) output << array[idx]  << "  ";
     output << endl;
     
     Heap<int> minHeap;
     for(int idx =0; idx < 8; idx++){
         minHeap.clear();
         minHeap.heapify(array, idx+1);
         output << "Min heap: " << minHeap.toString() << endl;
     }
     const int& a = minHeap.peek();
  
     output << "a = " << a << endl;
    string expect ="Input array: 50  20  15  10  8  6  7  23  \n\
Min heap: [50]\n\
Min heap: [20,50]\n\
Min heap: [15,50,20]\n\
Min heap: [10,15,20,50]\n\
Min heap: [8,10,20,50,15]\n\
Min heap: [6,10,8,50,15,20]\n\
Min heap: [6,10,7,50,15,20,8]\n\
Min heap: [6,10,7,23,15,20,8,50]\n\
a = 6\n";
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
