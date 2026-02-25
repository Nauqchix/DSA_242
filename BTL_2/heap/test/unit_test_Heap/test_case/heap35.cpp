#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap35() {
  string name = "heap35";
  Point* array[] = {
    new Point(13.1, 12.4), new Point(5.5, 4.5), new Point(15.5, 14.5),
    new Point(23.1, 12.4), new Point(35.5, 14.5), new Point(5.5, 34.5)
};
stringstream output;
Heap<Point*> heap(&myPointComparatorMAX, &Heap<Point*>::free);
for(int idx=0; idx < 6; idx++) heap.push(array[idx]);
output<<heap.toString(&myPoint2Str);

for(Heap<Point*>::Iterator it = heap.begin(); it != heap.end(); it++){
    Point* point = *it;
    output << point->radius() << ", ";
}
output << endl;
    string expect ="[[    36,     14],[    23,     12],[   5.5,     34],[   5.5,    4.5],[    16,     14],[    13,     12]]38.3471, 26.2177, 34.9357, 7.10634, 21.225, 18.038, \n";
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
// template<class T>
// void Heap<T>::heapsort(XArrayList<T>& arrayList) {
//     // Bước 1: Xoá dữ liệu cũ trong heap
//     elements.clear(); // Giả sử elements là XArrayList<T>

//     // Bước 2: Thêm từng phần tử từ arrayList vào heap và in ra heap sau mỗi lần heap up
//     for (int i = 0; i < arrayList.size(); ++i) {
//         push(arrayList.get(i));   // push đã gọi heapUp bên trong
//         printHeap();              // in ra heap sau mỗi lần heapUp
//     }

//     // Bước 3: Rút phần tử theo thứ tự sắp xếp từ heap, gán lại vào arrayList
//     for (int i = 0; i < arrayList.size(); ++i) {
//         arrayList.set(i, pop());
//     }
// }