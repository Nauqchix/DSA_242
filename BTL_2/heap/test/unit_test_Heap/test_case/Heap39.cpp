#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap39()
{
    string name = "Heap39";
 //! data ------------------------------------
 Heap<int> heap;
 heap.push(4);
 heap.push(2);
 heap.push(1);

 //! expect ----------------------------------
 string expect = "size=0;empty=1;[]";

 //! output ----------------------------------
    stringstream output;
 
    XArrayList<int> *arrayList =new XArrayList<int>();

    heap.heapsort(*arrayList);
    output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
    << heap.toString();
 //! remove data -----------------------------
 return printResult(output.str(), expect, name);
}
