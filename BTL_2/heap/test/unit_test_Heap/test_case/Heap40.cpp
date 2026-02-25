#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap40()
{
    string name = "Heap40";
    Heap<int> heap(maxHeapComparator);
    heap.push(4);
    heap.push(2);
    heap.push(1);
  
    //! expect ----------------------------------
    string expect = "[9000, 9000, 33, 22, 11, 5, 1, 0]\n";
  
    //! output ----------------------------------
    stringstream output;
    
      XArrayList<int> arrayList;
      arrayList.add(11);
      arrayList.add(22);
      arrayList.add(33);
      arrayList.add(0);
      arrayList.add(1);
      arrayList.add(9000);
      arrayList.add(9000);
      arrayList.add(5);
      cout<<"output : \n";
     heap.heapsort(arrayList);
     cout<<"expect : \n[11]\n\
[22,11]\n\
[33,11,22]\n\
[33,11,22,0]\n\
[33,11,22,0,1]\n\
[9000,11,33,0,1,22]\n\
[9000,11,9000,0,1,22,33]\n\
[9000,11,9000,5,1,22,33,0]\n";
 
     output << arrayList.toString()<<endl;
    //! remove data -----------------------------
  
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
