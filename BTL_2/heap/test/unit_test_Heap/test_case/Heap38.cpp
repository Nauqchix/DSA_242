#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap38()
{
    string name = "Heap38";
    Heap<int> heap(maxHeapComparator);
    heap.push(4);
    heap.push(2);
    heap.push(1);
  
    //! expect ----------------------------------
    string expect = "[9000, 9000, 9000, 4000, 2000, 1000, 33, 22, 11, 5, 1, 0]\n";
  
    //! output ----------------------------------
    stringstream output;
    
      XArrayList<int> arrayList;
      arrayList.add(11);
      arrayList.add(22);
      arrayList.add(33);
      arrayList.add(0);
      arrayList.add(1);
      arrayList.add(1000);
      arrayList.add(2000);
      arrayList.add(4000);
      arrayList.add(9000);
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
[1000,11,33,0,1,22]\n\
[2000,11,1000,0,1,22,33]\n\
[4000,2000,1000,11,1,22,33,0]\n\
[9000,4000,1000,2000,1,22,33,0,11]\n\
[9000,9000,1000,2000,4000,22,33,0,11,1]\n\
[9000,9000,1000,2000,9000,22,33,0,11,1,4000]\n\
[9000,9000,1000,2000,9000,22,33,0,11,1,4000,5]\n";
 
     output << arrayList.toString()<<endl;
    //! remove data -----------------------------
  
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
 }

