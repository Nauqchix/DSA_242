#ifndef UNIT_TEST_Heap_HPP
#define UNIT_TEST_Heap_HPP
#include"util/Point.h"
#include"util/sampleFunc.h"
#include"list/DLinkedList.h"
#include"list/XArrayList.h"
#include "Heap/Heap.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_Heap : public UNIT_TEST
{
public:
  UNIT_TEST_Heap()
  {
    REGISTER_TEST(heap01);

    REGISTER_TEST(heap02);

    REGISTER_TEST(heap03);

    REGISTER_TEST(heap04);

    REGISTER_TEST(heap05);

    REGISTER_TEST(heap06);

    REGISTER_TEST(heap07);

    REGISTER_TEST(heap08);

    REGISTER_TEST(heap09);

    REGISTER_TEST(heap10);

    REGISTER_TEST(heap11);

    REGISTER_TEST(heap12);

    REGISTER_TEST(heap13);

    REGISTER_TEST(heap14);

    REGISTER_TEST(heap15);

    REGISTER_TEST(heap16);

    REGISTER_TEST(heap17);

    REGISTER_TEST(heap18);

    REGISTER_TEST(heap19);

    REGISTER_TEST(heap20);

    REGISTER_TEST(heap21);

    REGISTER_TEST(heap22);

    REGISTER_TEST(heap23);

    REGISTER_TEST(heap24);

    REGISTER_TEST(heap25);

    REGISTER_TEST(heap26);

    REGISTER_TEST(heap27);

    REGISTER_TEST(heap28);

    REGISTER_TEST(heap29);

    REGISTER_TEST(heap30);

    REGISTER_TEST(heap31);

    REGISTER_TEST(heap32);

    REGISTER_TEST(heap33);

    REGISTER_TEST(heap34);

    REGISTER_TEST(heap35);

    REGISTER_TEST(heap36);

    REGISTER_TEST(heap37);

    REGISTER_TEST(heap38);

    REGISTER_TEST(heap39);

    REGISTER_TEST(heap40);
  }

private:
  bool heap01();

  bool heap02();

  bool heap03();

  bool heap04();

  bool heap05();

  bool heap06();

  bool heap07();

  bool heap08();

  bool heap09();

  bool heap10();

  bool heap11();

  bool heap12();

  bool heap13();

  bool heap14();

  bool heap15();

  bool heap16();

  bool heap17();

  bool heap18();

  bool heap19();

  bool heap20();

  bool heap21();

  bool heap22();

  bool heap23();

  bool heap24();

  bool heap25();

  bool heap26();

  bool heap27();

  bool heap28();

  bool heap29();

  bool heap30();

  bool heap31();

  bool heap32();

  bool heap33();

  bool heap34();

  bool heap35();

  bool heap36();

  bool heap37();

  bool heap38();

  bool heap39();

  bool heap40();
};
int maxHeapComparator(int*& lhs, int*& rhs);

int minHeapComparator(int*& lhs, int*& rhs);
int myPointComparator(Point*&  lhs, Point*& rhs);
int myPointComparatorMAX(Point*&  lhs, Point*& rhs);
string myPoint2Str(Point*& point);
string strInt(int*& str);

void deleteInt(int* a);
int myIntComparator(int& lhs, int& rhs);
#endif // UNIT_TEST_Heap_HPP
