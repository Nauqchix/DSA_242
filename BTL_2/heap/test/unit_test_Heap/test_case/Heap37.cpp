#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap37()
{
    string name = "Heap37";
   //! data ------------------------------------
   Heap<int> heap;
   heap.push(4);
   heap.push(2);
   heap.push(1);
 
   //! expect ----------------------------------
   string expect = "[0, 1, 5, 11, 22, 33, 1000, 2000, 4000, 9000, 9000, 9000]\n";
 
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
    cout<<"expect :\n [11]\n\
[11,22]\n\
[11,22,33]\n\
[0,11,33,22]\n\
[0,1,33,22,11]\n\
[0,1,33,22,11,1000]\n\
[0,1,33,22,11,1000,2000]\n\
[0,1,33,22,11,1000,2000,4000]\n\
[0,1,33,22,11,1000,2000,4000,9000]\n\
[0,1,33,22,11,1000,2000,4000,9000,9000]\n\
[0,1,33,22,11,1000,2000,4000,9000,9000,9000]\n\
[0,1,5,22,11,33,2000,4000,9000,9000,9000,1000]\n";
    output << arrayList.toString()<<endl;
   //! remove data -----------------------------
 
   //! result ----------------------------------
   return printResult(output.str(), expect, name);
}
