#include "unit_test_hash.hpp"
void newINT_delete(int* value) { delete value; }
bool newINT_EQ(int*& a, int*& b) { return *a == *b; }
int newINT_keyHash(int*& key, int capacity) { return *key % capacity; }
string newINT_toString(int*& key) { return "n_" + to_string(*key); }
int hashFunc(int& key, int tablesize) {
    return key % tablesize;
}
int hashFunc(int*& item, int size) {
    return *item % size;
}

bool keyEQ(int*& lhs, int*& rhs) {
    return *lhs == *rhs;
}

void deleteKey(int *key) {
    delete key;
}

string key2str(int*& item) {
    stringstream os;
    os << *item;
    return os.str();
}

bool valueEQ(int*& lhs, int*& rhs) {
    return *lhs == *rhs;
}

string value2str(int*& item) {
    stringstream os;
    os << *item;
    return os.str();
}

int stringHash(string& str, int size) {
    long long int sum = 0;
    for (int idx = 0; idx < str.length(); idx++) sum += str[idx];
    return sum % size;
}
