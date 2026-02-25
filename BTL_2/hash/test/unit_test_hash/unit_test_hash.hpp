#ifndef UNIT_TEST_Hash_HPP
#define UNIT_TEST_Hash_HPP

 #include"util/sampleFunc.h"
#include"util/Point.h"
#include"list/DLinkedList.h"
#include"list/XArrayList.h"
#include "Hash/xMap.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_Hash : public UNIT_TEST
{
public:
  UNIT_TEST_Hash()
  {
    REGISTER_TEST(hash01);

    REGISTER_TEST(hash02);

    REGISTER_TEST(hash03);

    REGISTER_TEST(hash04);

    REGISTER_TEST(hash05);

    REGISTER_TEST(hash06);

    REGISTER_TEST(hash07);

    REGISTER_TEST(hash08);

    REGISTER_TEST(hash09);

    REGISTER_TEST(hash10);

    REGISTER_TEST(hash11);

    REGISTER_TEST(hash12);

    REGISTER_TEST(hash13);

    REGISTER_TEST(hash14);

    REGISTER_TEST(hash15);

    REGISTER_TEST(hash16);

    REGISTER_TEST(hash17);

    REGISTER_TEST(hash18);

    REGISTER_TEST(hash19);

    REGISTER_TEST(hash20);

    REGISTER_TEST(hash21);

    REGISTER_TEST(hash22);

    REGISTER_TEST(hash23);

    REGISTER_TEST(hash24);

    REGISTER_TEST(hash25);

    REGISTER_TEST(hash26);

    REGISTER_TEST(hash27);

    REGISTER_TEST(hash28);

    REGISTER_TEST(hash29);

    REGISTER_TEST(hash30);

    REGISTER_TEST(hash31);

    REGISTER_TEST(hash32);

    REGISTER_TEST(hash33);

    REGISTER_TEST(hash34);

    REGISTER_TEST(hash35);

    REGISTER_TEST(hash36);

    REGISTER_TEST(hash37);
    REGISTER_TEST(hash38);
  }

private:
  bool hash01();

  bool hash02();

  bool hash03();

  bool hash04();

  bool hash05();

  bool hash06();

  bool hash07();

  bool hash08();

  bool hash09();

  bool hash10();

  bool hash11();

  bool hash12();

  bool hash13();

  bool hash14();

  bool hash15();

  bool hash16();

  bool hash17();

  bool hash18();

  bool hash19();

  bool hash20();

  bool hash21();

  bool hash22();

  bool hash23();

  bool hash24();

  bool hash25();

  bool hash26();

  bool hash27();

  bool hash28();

  bool hash29();

  bool hash30();
  bool hash31();

  bool hash32();

  bool hash33();

  bool hash34();

  bool hash35();

  bool hash36();

  bool hash37();

  bool hash38();
};
void newINT_delete(int* value);
bool newINT_EQ(int*& a, int*& b);
int newINT_keyHash(int*& key, int capacity);
string newINT_toString(int*& key);
int hashFunc(int& key, int tablesize);
int hashFunc(int*& item, int size);

bool keyEQ(int*& lhs, int*& rhs);

void deleteKey(int *key);

string key2str(int*& item);

bool valueEQ(int*& lhs, int*& rhs);

string value2str(int*& item);
int stringHash(string& str, int size);

#endif // UNIT_TEST_Hash_HPP
