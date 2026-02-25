#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap36()
{
    string name = "Heap36";
   //! data ------------------------------------
   Heap<int> heap;
   heap.push(4);
   heap.push(2);
   heap.push(1);
 
   //! expect ----------------------------------
   string expect = "size=0;empty=1;[]";
 
   //! output ----------------------------------
   stringstream output;
   
        XArrayList<int> arrayList;

        heap.heapsort(arrayList);
        output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
          << heap.toString();
   //! remove data -----------------------------
 
   //! result ----------------------------------
   return printResult(output.str(), expect, name);
}
