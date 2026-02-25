#ifndef INVENTORY_COMPRESSOR_H
#define INVENTORY_COMPRESSOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include "inventory.h"
#include "hash/xMap.h"
#include "heap/Heap.h"
#include "list/XArrayList.h"
//! thêm này vô để chạy test
namespace std {
    inline ostream& operator<<(ostream& os, const pair<char, int>& p) {
        os << "(" << p.first << ", " << p.second << ")";
        return os;
    }
}
template<int treeOrder>
class HuffmanTree {
public:
    struct HuffmanNode {
        char symbol;
        int freq;
        XArrayList<HuffmanNode*> children;

        static int globalCounter;    
        int order;


        HuffmanNode(char s, int f): symbol(s), freq(f), children(), order(globalCounter++){}
    HuffmanNode(int f, const XArrayList<HuffmanNode*>& childs) : symbol('\0'), freq(f), children(childs), order(globalCounter++){}
    };

    HuffmanTree();
    ~HuffmanTree();
    static int cmp(HuffmanNode* &a, HuffmanNode* &b);
    void build(XArrayList<pair<char, int>>& symbolsFreqs);
    void generateCodes(xMap<char, std::string>& table);
    std::string decode(const std::string& huffmanCode);

private:
    HuffmanNode* root;
};

template<int treeOrder>
class InventoryCompressor {
public:
    InventoryCompressor(InventoryManager* manager);
    ~InventoryCompressor();

    void buildHuffman();
    void printHuffmanTable();
    std::string productToString(const List1D<InventoryAttribute>& attributes, const std::string& name);
    std::string encodeHuffman(const List1D<InventoryAttribute>& attributes, const std::string& name);
    std::string decodeHuffman(const std::string& huffmanCode, List1D<InventoryAttribute>& attributesOutput, std::string& nameOutput);

private:
    xMap<char, std::string>* huffmanTable;
    InventoryManager* invManager;
    HuffmanTree<treeOrder>* tree;
};


#endif // INVENTORY_COMPRESSOR_H

template <int treeOrder>
HuffmanTree<treeOrder>::HuffmanTree()
{
    this->root = nullptr;
}

template<int treeOrder>
int HuffmanTree<treeOrder>::HuffmanNode::globalCounter = 0;

template<int treeOrder>
int HuffmanTree<treeOrder>::cmp(HuffmanNode* &a, HuffmanNode* &b){
        if (a->freq < b->freq) return -1;
        else if (a->freq > b->freq) return 1;
        else if (a->order < b->order) return -1;
        else if (a->order > b->order) return  1;
        else return  0;
}

template <int treeOrder>
HuffmanTree<treeOrder>::~HuffmanTree()
{
    //TODO
    if (!root) return;
    auto delete_loop = [&](auto&& self, HuffmanNode* node) -> void {
        for (int i = 0; i < node->children.size(); ++i) {
            self(self, node->children.get(i));
        }
        delete node;
    };
    delete_loop(delete_loop, root);
    root = nullptr;  
    
}

template <int treeOrder>
void HuffmanTree<treeOrder>::build(XArrayList<pair<char, int>>& symbolsFreqs)
{
    //TODO
    Heap<HuffmanNode*> heapbuild(&cmp);
    int Lc = symbolsFreqs.size();
    int dummyNodeCount = 0;
    for (int i = 0; i < Lc; i++) {
        pair<char, int> symbolFreq = symbolsFreqs.get(i);
        heapbuild.push(new HuffmanNode(symbolFreq.first, symbolFreq.second));
    }
    int ensureFactor =  (Lc - 1) % (treeOrder - 1);
    if (ensureFactor != 0){
        dummyNodeCount = (treeOrder - 1) - ensureFactor;
    }
    for(int i = 0; i < dummyNodeCount; i++){
        heapbuild.push(new HuffmanNode('\0', 0));
    }
    while(heapbuild.size() > 1){
        XArrayList<HuffmanNode*> ParentNode;
        int sum = 0;
        for (int i = 0; i < treeOrder; ++i) {
            auto node = heapbuild.pop();
            ParentNode.add(node);
            sum += node->freq;
        }
        heapbuild.push(new HuffmanNode(sum, ParentNode));
    }
    root = heapbuild.empty() ? nullptr : heapbuild.pop();
}

template <int treeOrder>
void HuffmanTree<treeOrder>::generateCodes(xMap<char, std::string> &table)
{
    //TODO
    if (!root) return;
    if (root->children.empty() && root->symbol != '\0') {
        int idx = treeOrder - 1;
        char digit = (idx < 10 ? '0' + idx : 'a' + (idx - 10));
        table.put(root->symbol, string(1, digit));
        return;
    }
  auto makeCode = [&](auto&& self, HuffmanNode* node,const std::string& prefix) -> void {
    if (node->children.empty()) {
      if (node->symbol != '\0') table.put(node->symbol, prefix);
      return;
    }
    for (int i = 0; i < node->children.size(); ++i) {
      char digit = (i < 10 ? '0' + i : 'a' + (i - 10));
      self(self, node->children.get(i), prefix + digit);
    }
  };
  makeCode(makeCode, root, "");

}

template <int treeOrder>
std::string HuffmanTree<treeOrder>::decode(const std::string &huffmanCode)
{
    //TODO
    if (!root || huffmanCode.empty()) return "";
    if (root->children.empty() && root->symbol != '\0') {
        return string(huffmanCode.size(), root->symbol);
    }
    string decode_buffer;
    HuffmanNode* cur = root;
    for (char c : huffmanCode) {
        int idx = -1;
        if      (c >= '0' && c <= '9') idx = c - '0';
        else if (c >= 'a' && c <= 'f') idx = 10 + (c - 'a');
        else continue;
        if (idx < 0 || idx >= cur->children.size()) break;
        cur = cur->children.get(idx);
        if (cur->children.size() == 0) {
            if (cur->symbol != '\0') decode_buffer += cur->symbol;
            cur = root;
        }
    }
    return decode_buffer;
}

template <int treeOrder>
InventoryCompressor<treeOrder>::InventoryCompressor(InventoryManager *manager)
{
    //TODO
    this->invManager = manager;
    this->tree = new HuffmanTree<treeOrder>();
    this->huffmanTable = new xMap<char, string>(xMap<char, string>::simpleHash, 0.75f);
}

template <int treeOrder>
InventoryCompressor<treeOrder>::~InventoryCompressor()
{
    //TODO
    if(tree != nullptr){
        delete tree;
        tree = nullptr;
    }
    if(huffmanTable != nullptr){
        delete huffmanTable;
        huffmanTable = nullptr;
    }
}

template <int treeOrder>
void InventoryCompressor<treeOrder>::buildHuffman()
{
    //TODO
    xMap<char, int> freqMap(xMap<char, int>::simpleHash, 0.75f);
    int n = invManager->size();
    for(int i = 0; i < n; i++){
        string name = invManager->getProductName(i);
        List1D<InventoryAttribute> feature = invManager->getProductAttributes(i);
        string buffer = productToString(feature, name);
        for (char c : buffer) {
            if (freqMap.containsKey(c)) {
                freqMap.put(c, freqMap.get(c) + 1);
            } else {
                freqMap.put(c, 1);
            }
        }
    }
    XArrayList<std::pair<char,int>> syms;
for (char c : freqMap.keys()) {
    syms.add({c, freqMap.get(c)});
}
    tree->build(syms);
    tree->generateCodes(*huffmanTable);


}

template <int treeOrder>
void InventoryCompressor<treeOrder>::printHuffmanTable() {
    DLinkedList<char> keys = huffmanTable->keys();
    for (char ch : keys) {
        std::cout << "'" << ch << "' : " << huffmanTable->get(ch) << std::endl;
    }
}

template <int treeOrder>
std::string InventoryCompressor<treeOrder>::productToString(const List1D<InventoryAttribute> &attributes, const std::string &name)
{
    //TODO
    ostringstream ss;
    ss << fixed << setprecision(6);
    ss << name << ":";

    for (int i = 0; i < attributes.size(); ++i) {
        if (i > 0) ss << ", ";  
        const auto &attr = attributes.get(i);
        ss << "(" << attr.name << ": " << attr.value << ")";
    }


return ss.str();
}

template <int treeOrder>
std::string InventoryCompressor<treeOrder>::encodeHuffman(const List1D<InventoryAttribute> &attributes, const std::string &name)
{
    //TODO
    if (huffmanTable->empty()) {
        buildHuffman();
    }
    string encode_script = this->productToString(attributes, name);
    string result;
    for (char c : encode_script) {
        result += huffmanTable->get(c);
    }
    return result;
}

template <int treeOrder>
std::string InventoryCompressor<treeOrder>::decodeHuffman(const std::string &huffmanCode, List1D<InventoryAttribute> &attributesOutput, std::string &nameOutput)
{
    //TODO
    string decoded = tree->decode(huffmanCode);
    auto sep = decoded.find(':');
    if (sep == std::string::npos) {
        throw std::runtime_error("Invalid encoded string: missing ':' separator");
    }
    nameOutput = decoded.substr(0, sep);
    string payload = decoded.substr(sep + 1);
    size_t pos = 0;

    while (true) {
        auto start = payload.find('(', pos);
        if (start == string::npos) break;
        auto end = payload.find(')', start);
        if (end == string::npos) break;
        string token = payload.substr(start + 1, end - start - 1);
        auto colon = token.find(':');
        if (colon != std::string::npos) {
            string key = token.substr(0, colon);
            string num = token.substr(colon + 1);
            double value = 0.0;
            try {
                value = stod(num);
            } catch (const std::exception &e) {
                throw std::runtime_error("Invalid numeric value in encoded data: " + num);
            }
            attributesOutput.add(InventoryAttribute(key, value));
        }

        pos = end + 1;
    }

    return decoded;
}