#include "../unit_test_Heap.hpp"

bool UNIT_TEST_Heap::heap34() {
  string name = "heap34";
  Point array[] = {
    Point(13.1, 12.4), Point(5.5, 4.5), Point(15.5, 14.5),
    Point(23.1, 12.4), Point(35.5, 14.5), Point(5.5, 34.5)
};
stringstream output;
Heap<Point> minHeap1(minHeapComparator);
output << "Min Heap: ";
minHeap1.heapify(array, 6);
output << minHeap1.toString(&point2str) << endl;

Heap<Point> maxHeap(maxHeapComparator);
output << "Max Heap: ";
maxHeap.heapify(array, 6);
output << maxHeap.toString(&point2str) << endl;
    string expect ="Min Heap: [(5.5, 4.5),(13.1, 12.4),(15.5, 14.5),(23.1, 12.4),(35.5, 14.5),(5.5, 34.5)]\n\
Max Heap: [(35.5, 14.5),(23.1, 12.4),(5.5, 34.5),(5.5, 4.5),(15.5, 14.5),(13.1, 12.4)]\n";
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
