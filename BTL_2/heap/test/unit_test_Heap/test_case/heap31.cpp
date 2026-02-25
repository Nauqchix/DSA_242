#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap31() {
  string name = "heap31";
  Heap<int> heap;
     int array[] = {50, 20, 15, 10, 8, 6, 7, 23}; 
     for(int idx =0; idx < 8; idx++) heap.push(array[idx]);
     stringstream output;
     output<<heap.toString();
     heap.pop();
     output<<heap.toString();
     heap.push(5);
     output<<heap.toString();
     
     Heap<int> maxHeap(&myIntComparator);
     for(int idx =0; idx < 8; idx++) maxHeap.push(array[idx]);
     output << maxHeap.toString();
     maxHeap.pop();
     output << maxHeap.toString();
     maxHeap.push(70);
     output << maxHeap.toString();
    string expect ="[6,10,7,23,15,20,8,50][7,10,8,23,15,20,50][5,7,8,10,15,20,50,23][50,23,15,20,8,6,7,10][23,20,15,10,8,6,7][70,23,15,20,8,6,7,10]";
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
