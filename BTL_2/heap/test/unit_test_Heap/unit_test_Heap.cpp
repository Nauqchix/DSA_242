#include"unit_test_Heap.hpp"
int maxHeapComparator(int*& lhs, int*& rhs) {
    if (*lhs < *rhs) {
      return +1;
    } else if (*lhs > *rhs) {
      return -1;
    } else {
      return 0;
    }
  }
  
  int minHeapComparator(int*& lhs, int*& rhs) {
    if (*lhs < *rhs) {
      return -1;
    } else if (*lhs > *rhs) {
      return +1;
    } else {
      return 0;
    }
  }
  int myPointComparator(Point*&  lhs, Point*& rhs){
    if(lhs->radius() < rhs->radius()) return -1;
    else if(lhs->radius() > rhs->radius()) return +1;
    else return 0;
}
int myPointComparatorMAX(Point*&  lhs, Point*& rhs){
    if(lhs->radius() < rhs->radius()) return +1;
    else if(lhs->radius() > rhs->radius()) return -1;
    else return 0;
}

string myPoint2Str(Point*& point){
    stringstream os;
    os << "["   << setw(6) << setprecision(2) << point->getX() 
                << ", "
                << setw(6) << setprecision(2) << point->getY()
       << "]";
    return os.str();
}
  string strInt(int*& str) { return to_string(*str); }
  
  void deleteInt(int* a) { delete a; }
  int myIntComparator(int& lhs, int& rhs){
    if(lhs < rhs) return +1;
    else if(lhs > rhs) return -1;
    else return 0;
}