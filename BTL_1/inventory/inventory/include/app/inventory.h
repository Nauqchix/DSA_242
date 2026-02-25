#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include "list/XArrayList.h"
#include "list/DLinkedList.h"
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

// -------------------- List1D --------------------
template <typename T>
class List1D
{
private:
    IList<T> *pList;

public:
    List1D();
    List1D(int num_elements);
    List1D(const T *array, int num_elements);
    List1D(const List1D<T> &other);
    virtual ~List1D();
    List1D<T> &operator=(const List1D<T> &other);
    int size() const;
    T get(int index) const;
    void set(int index, T value);
    void add(const T &value);
    string toString() const;
    friend ostream &operator<<(ostream &os, const List1D<T> &list)
    {
        os << list.toString();
        return os;
    }
};

template <typename T>
class List2D
{
private:
    IList<IList<T> *> *pMatrix;

public:
    List2D();
    List2D(List1D<T> *array, int num_rows);
    List2D(const List2D<T> &other);
    virtual ~List2D();
    List2D<T> &operator=(const List2D<T> &other);
    int rows() const;
    //! thêm hàm này

    void setRow(int rowIndex, const List1D<T> &row);
    T get(int rowIndex, int colIndex) const;
    List1D<T> getRow(int rowIndex) const;
    string toString() const;
    friend ostream &operator<<(ostream &os, const List2D<T> &matrix)
    {
        os << matrix.toString();
        return os;
    }
};
struct InventoryAttribute
{
    string name;
    double value;
    //! thêm
    InventoryAttribute() : name(""), value(0.0) {} // Constructor mặc định
    InventoryAttribute(const string &name, double value) : name(name), value(value) {}
    string toString() const { return name + ": " + to_string(value); }
    //! thêm
    // Định nghĩa toán tử so sánh ==
    bool operator==(const InventoryAttribute &other) const
    {
        return name == other.name && value == other.value;
    }
    // Toán tử in ra ostream
    friend std::ostream &operator<<(std::ostream &os, const InventoryAttribute &attr)
    {
        return os << attr.toString();
    }
};

// -------------------- InventoryManager --------------------
class InventoryManager
{
private:
    List2D<InventoryAttribute> attributesMatrix;
    List1D<string> productNames;
    List1D<int> quantities;

public:
    InventoryManager();

    InventoryManager(const List2D<InventoryAttribute> &matrix,
                     const List1D<string> &names,
                     const List1D<int> &quantities);

    InventoryManager(const InventoryManager &other);

    int size() const;

    List1D<InventoryAttribute> getProductAttributes(int index) const;
    string getProductName(int index) const;
    int getProductQuantity(int index) const;
    void updateQuantity(int index, int newQuantity);
    void addProduct(const List1D<InventoryAttribute> &attributes, const string &name, int quantity);
    void removeProduct(int index);

    List1D<string> query(string attributeName, const double &minValue,
                         const double &maxValue, int minQuantity, bool ascending) const;

    void removeDuplicates();

    static InventoryManager merge(const InventoryManager &inv1,
                                  const InventoryManager &inv2);

    void split(InventoryManager &section1,
               InventoryManager &section2,
               double ratio) const;

    List2D<InventoryAttribute> getAttributesMatrix() const;
    List1D<string> getProductNames() const;
    List1D<int> getQuantities() const;
    string toString() const;
};
// -------------------- List1D Method Definitions --------------------
template <typename T>
List1D<T>::List1D()
{
    // TODO
    this->pList = new DLinkedList<T>();
}

template <typename T>
List1D<T>::List1D(int num_elements)
{
    // TODO
    this->pList = new DLinkedList<T>();
    for (int i = 0; i < num_elements; i++)
    {
        pList->add(T());
    }
}

template <typename T>
List1D<T>::List1D(const T *array, int num_elements)
{
    // TODO
    this->pList = new DLinkedList<T>();
    for (int i = 0; i < num_elements; i++)
    {
        pList->add(array[i]);
    }
}

template <typename T>
List1D<T>::List1D(const List1D<T> &other)
{
    // TODO
    this->pList = new DLinkedList<T>();
    for (int i = 0; i < other.size(); i++)
    {
        pList->add(other.get(i));
    }
}

template <typename T>
List1D<T>::~List1D()
{
    // TODO
    delete pList;
}
template <typename T>
List1D<T> &List1D<T>::operator=(const List1D<T> &other)
{
    delete pList;
    pList = new DLinkedList<T>();
    for (int i = 0; i < other.size(); i++)
    {
        pList->add(other.get(i));
    }
    return *this;
}

template <typename T>
int List1D<T>::size() const
{
    // TODO
    return pList->size();
}

template <typename T>
T List1D<T>::get(int index) const
{
    // TODO
    if (pList == nullptr || index < 0 || index >= pList->size())
    {
        throw out_of_range("Index is out of range!");
    }
    return pList->get(index);
}

template <typename T>
void List1D<T>::set(int index, T value)
{
    // TODO
    if (index < 0 || index > pList->size())
    {
        throw out_of_range("Index is out of range!");
    }
    if (index < pList->size())
    {
        pList->removeAt(index);
    }
    pList->add(index, value);
}

template <typename T>
void List1D<T>::add(const T &value)
{
    // TODO
    pList->add(value);
}

template <typename T>
string List1D<T>::toString() const
{
    // TODO
    if (pList == nullptr || pList->size() == 0)
        return "[]";
    stringstream ss;
    ss << "[";
    for (int i = 0; i < size(); i++)
    {
        ss << get(i);
        if (i < size() - 1)
            ss << ", ";
    }
    ss << "]";
    return ss.str();
}

// -------------------- List2D Method Definitions --------------------
template <typename T>
List2D<T>::List2D()
{
    // TODO
    pMatrix = new DLinkedList<IList<T> *>();
}
template <typename T>
List2D<T> &List2D<T>::operator=(const List2D<T> &other)
{
    while (pMatrix->size() > 0)
    {
        delete pMatrix->removeAt(0);
    }
    delete pMatrix;
    pMatrix = new DLinkedList<IList<T> *>();
    for (int i = 0; i < other.rows(); i++)
    {
        IList<T> *newRow = new DLinkedList<T>();
        List1D<T> row = other.getRow(i);
        for (int j = 0; j < row.size(); j++)
        {
            newRow->add(row.get(j));
        }
        pMatrix->add(newRow);
    }
    return *this;
}

template <typename T>
List2D<T>::List2D(List1D<T> *array, int num_rows)
{
    pMatrix = new DLinkedList<IList<T> *>();
    for (int i = 0; i < num_rows; i++)
    {
        IList<T> *row = new DLinkedList<T>();
        for (int j = 0; j < array[i].size(); j++)
        {
            row->add(array[i].get(j));
        }
        pMatrix->add(row);
    }
}

template <typename T>
List2D<T>::List2D(const List2D<T> &other)
{
    // TODO
    pMatrix = new DLinkedList<IList<T> *>();
    for (int i = 0; i < other.rows(); i++)
    {
        IList<T> *newRow = new DLinkedList<T>();
        List1D<T> row = other.getRow(i);
        for (int j = 0; j < row.size(); j++)
        {
            newRow->add(row.get(j));
        }
        pMatrix->add(newRow);
    }
}

template <typename T>
List2D<T>::~List2D()
{
    // TODO
    while (pMatrix->size() > 0)
    {
        delete pMatrix->removeAt(0);
    }
    delete pMatrix;
}

template <typename T>
int List2D<T>::rows() const
{
    return pMatrix->size();
}

template <typename T>
void List2D<T>::setRow(int rowIndex, const List1D<T> &row)
{
    // TODO
    if (rowIndex < 0 || rowIndex > pMatrix->size())
    {
        throw out_of_range("Index is out of range!");
    }

    IList<T> *value = new DLinkedList<T>();
    for (int i = 0; i < row.size(); i++)
    {
        value->add(row.get(i));
    }

    if (rowIndex < pMatrix->size())
    {
        delete pMatrix->removeAt(rowIndex);
    }

    pMatrix->add(rowIndex, value);
}

template <typename T>
T List2D<T>::get(int rowIndex, int colIndex) const
{
    // TODO
    return pMatrix->get(rowIndex)->get(colIndex);
}

template <typename T>
List1D<T> List2D<T>::getRow(int rowIndex) const
{
    // TODO
    List1D<T> track;
    IList<T> *rowPtr = pMatrix->get(rowIndex);

    for (int i = 0; i < rowPtr->size(); i++)
    {
        track.add(rowPtr->get(i));
    }

    return track;
}

template <typename T>
string List2D<T>::toString() const
{
    // TODO
    stringstream ss;
    ss << "[";
    for (int i = 0; i < rows(); i++)
    {
        ss << getRow(i).toString();
        if (i < rows() - 1)
            ss << ", ";
    }
    ss << "]";
    return ss.str();
}

#include "app/inventory.h"
// // -------------------- InventoryManager Method Definitions --------------------
InventoryManager::InventoryManager()
{
    // TODO
    attributesMatrix = List2D<InventoryAttribute>();
    productNames = List1D<string>();
    quantities = List1D<int>();
}

InventoryManager::InventoryManager(const List2D<InventoryAttribute> &matrix,
                                   const List1D<string> &names,
                                   const List1D<int> &quantities)
{
    // TODO
    this->attributesMatrix = matrix;
    this->productNames = names;
    this->quantities = quantities;
}

InventoryManager::InventoryManager(const InventoryManager &other)
{
    // TODO
    attributesMatrix = other.attributesMatrix;
    productNames = other.productNames;
    quantities = other.quantities;
}

int InventoryManager::size() const
{
    // TODO
    return productNames.size();
}

List1D<InventoryAttribute> InventoryManager::getProductAttributes(int index) const
{
    // TODO
    if (index < 0 || index >= productNames.size())
    {
        throw out_of_range("Index is invalid!");
    }
    return attributesMatrix.getRow(index);
}

string InventoryManager::getProductName(int index) const
{
    // TODO
    if (index < 0 || index >= productNames.size())
    {
        throw out_of_range("Index is invalid!");
    }
    return productNames.get(index);
}

int InventoryManager::getProductQuantity(int index) const
{
    // TODO
    if (index < 0 || index >= productNames.size())
    {
        throw out_of_range("Index is invalid!");
    }
    return quantities.get(index);
}

void InventoryManager::updateQuantity(int index, int newQuantity)
{
    // TODO
    if (index < 0 || index >= productNames.size())
    {
        throw out_of_range("Index is invalid!");
    }
    quantities.set(index, newQuantity);
}

void InventoryManager::addProduct(const List1D<InventoryAttribute> &attributes, const string &name, int quantity)
{
    // TODO
    attributesMatrix.setRow(attributesMatrix.rows(), attributes);
    productNames.add(name);
    quantities.add(quantity);
}

void InventoryManager::removeProduct(int index)
{
    // TODO
    if (index < 0 || index >= productNames.size())
    {
        throw out_of_range("Index is invalid!");
    }
    List2D<InventoryAttribute> removedattributesmatrix;
    List1D<string> removedproductname;
    List1D<int> removedquantities;
    for (int i = 0; i < productNames.size(); i++)
    {
        if (i != index)
        {
            removedattributesmatrix.setRow(removedattributesmatrix.rows(), attributesMatrix.getRow(i));
            removedproductname.add(productNames.get(i));
            removedquantities.add(quantities.get(i));
        }
    }
    attributesMatrix = removedattributesmatrix;
    productNames = removedproductname;
    quantities = removedquantities;
}

List1D<string> InventoryManager::query(string attributeName, const double &minValue,
                                       const double &maxValue, int minQuantity, bool ascending) const
{
    List1D<string> returnList;
    List1D<string> tmp;
    List1D<InventoryAttribute> queryList;
    List1D<int> quantitiesList;

    for (int i = 0; i < productNames.size(); i++)
    {
        for (int j = 0; j < attributesMatrix.getRow(i).size(); j++)
        {
            InventoryAttribute attr = attributesMatrix.get(i, j);
            if (attr.name == attributeName && attr.value >= minValue && attr.value <= maxValue && quantities.get(i) >= minQuantity)
            {
                queryList.add(attr);
                tmp.add(productNames.get(i));
                quantitiesList.add(quantities.get(i));
            }
        }
    }

    for (int i = 1; i < tmp.size(); i++)
    {
        InventoryAttribute keyAttr = queryList.get(i);
        string keyStr = tmp.get(i);
        int keyQty = quantitiesList.get(i);

        int j = i - 1;

        while (j >= 0 && ((ascending && (queryList.get(j).value > keyAttr.value || (queryList.get(j).value == keyAttr.value && quantitiesList.get(j) > keyQty))) || (!ascending && (queryList.get(j).value < keyAttr.value || (queryList.get(j).value == keyAttr.value && quantitiesList.get(j) < keyQty)))))
        {
            queryList.set(j + 1, queryList.get(j));
            tmp.set(j + 1, tmp.get(j));
            quantitiesList.set(j + 1, quantitiesList.get(j));
            j--;
        }

        queryList.set(j + 1, keyAttr);
        tmp.set(j + 1, keyStr);
        quantitiesList.set(j + 1, keyQty);
    }

    for (int i = 0; i < tmp.size(); i++)
    {
        returnList.add(tmp.get(i));
    }

    return returnList;
}

void InventoryManager::removeDuplicates()
{
    // TODO
    for (int i = 0; i < productNames.size(); i++)
    {
        for (int j = i + 1; j < productNames.size();)
        {
            if (productNames.get(i) == productNames.get(j) &&
                getProductAttributes(i).toString() == getProductAttributes(j).toString())
            {
                quantities.set(i, quantities.get(i) + quantities.get(j));
                removeProduct(j);
            }
            else
            {
                j++;
            }
        }
    }
}
//! Hàm này có gọi removeDuplicates hay không
InventoryManager InventoryManager::merge(const InventoryManager &inv1,
                                         const InventoryManager &inv2)
{
    // TODO
    InventoryManager newInven = inv1;
    for (int i = 0; i < inv2.size(); i++)
    {
        newInven.addProduct(inv2.getProductAttributes(i), inv2.getProductName(i), inv2.getProductQuantity(i));
    }
    return newInven;
}

void InventoryManager::split(InventoryManager &section1, InventoryManager &section2, double ratio) const
{
    // TODO
    if (ratio <= 0)
    {
        section1 = InventoryManager();
        section2 = *this;
        return;
    }
    if (ratio >= 1)
    {
        section2 = InventoryManager();
        section1 = *this;
        return;
    }

    double scaledSize = productNames.size() * ratio;
    int new_size = (scaledSize - (int)scaledSize > 1e-6) ? ((int)scaledSize + 1) : (int)scaledSize;
    new_size = abs(new_size);

    section1 = InventoryManager();
    section2 = InventoryManager();

    for (int i = 0; i < new_size; i++)
    {
        section1.addProduct(getProductAttributes(i), getProductName(i), getProductQuantity(i));
    }

    for (int i = new_size; i < productNames.size(); i++)
    {
        section2.addProduct(getProductAttributes(i), getProductName(i), getProductQuantity(i));
    }
}

List2D<InventoryAttribute> InventoryManager::getAttributesMatrix() const
{
    // TODO
    return attributesMatrix;
}

List1D<string> InventoryManager::getProductNames() const
{
    // TODO
    return productNames;
}

List1D<int> InventoryManager::getQuantities() const
{
    // TODO
    return quantities;
}

string InventoryManager::toString() const
{
    // TODO
    stringstream ss;
    ss << "InventoryManager[\n";
    ss << "  AttributesMatrix: " << attributesMatrix.toString() << ",\n";
    ss << "  ProductNames: " << productNames.toString() << ",\n";
    ss << "  Quantities: " << quantities.toString() << "\n";
    ss << "]";
    return ss.str();
}

#endif /* INVENTORY_MANAGER_H */
