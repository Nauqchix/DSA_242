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

    int size() const;
    T get(int index) const;
    void set(int index, T value);
    void add(const T &value);
    string toString() const;
    template <typename U> //! thêm vào  để chạy test 
    friend ostream &operator<<(ostream &os, const List1D<T> &list);
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

    int rows() const;
    void setRow(int rowIndex, const List1D<T> &row);
    T get(int rowIndex, int colIndex) const;
    List1D<T> getRow(int rowIndex) const;
    string toString() const;
    template <typename U> //! thêm vào  để chạy test 
    friend ostream &operator<<(ostream &os, const List2D<T> &matrix);
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
    for (int i = 0; i < num_elements; i++){
        pList->add(T());
    }
  
}

template <typename T>
List1D<T>::List1D(const T *array, int num_elements)
{
    // TODO
    this->pList = new DLinkedList<T>();
    for(int i = 0; i < num_elements; i++){
        pList->add(array[i]);
    }
  
}

template <typename T>
List1D<T>::List1D(const List1D<T> &other)
{
    // TODO
    this->pList = new DLinkedList<T>();
        for(int i = 0; i < other.size(); i++){
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
int List1D<T>::size() const
{
    // TODO
   return pList->size();
}

template <typename T>
T List1D<T>::get(int index) const
{
    // TODO
    if (pList == nullptr || index < 0 || index >= pList->size()) {
        throw out_of_range("Index is out of range!");
    }
    return pList->get(index);
    
}

template <typename T>
void List1D<T>::set(int index, T value)
{
    // TODO
    if (index < 0 || index > pList->size()) {
        throw out_of_range("Index is out of range!");
    }
    if(index < pList->size()){
        pList-> removeAt(index);
    }
    pList->add(index, value);
}

template <typename T>
void List1D<T>::add(const T &value)
{
    // TODO
    pList-> add(value);
    
}

template <typename T>
string List1D<T>::toString() const
{
    // TODO
    if (pList == nullptr || pList->size() == 0) return "[]";
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

template <typename T>
ostream &operator<<(ostream &os, const List1D<T> &list)
{
    os << list.toString();
    return os;
   
}

// -------------------- List2D Method Definitions --------------------
template <typename T>
List2D<T>::List2D()
{
    // TODO
    pMatrix = new DLinkedList<IList<T> *>();
   
}

template <typename T>
List2D<T>::List2D(List1D<T> *array, int num_rows)
{
    pMatrix = new DLinkedList<IList<T> *>();
    for (int i = 0; i < num_rows; i++) {
        IList<T>* row = new DLinkedList<T>();
        for (int j = 0; j < array[i].size(); j++) {  
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
    for (int i = 0; i < other.rows(); i++) {
        IList<T>* newRow = new DLinkedList<T>();
        List1D<T> row = other.getRow(i);
        for (int j = 0; j < row.size(); j++) {
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
    if (rowIndex < 0 || rowIndex > pMatrix->size()) { 
        throw out_of_range("Index is out of range!"); 
    }

    IList<T>* value = new DLinkedList<T>();
    for (int i = 0; i < row.size(); i++) {
        value->add(row.get(i));
    }

    if (rowIndex < pMatrix->size()) {
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
    IList<T>* rowPtr = pMatrix->get(rowIndex);
    
    for (int i = 0; i < rowPtr->size(); i++) {
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

template <typename T>
ostream &operator<<(ostream &os, const List2D<T> &matrix)
{
    // TODO
    os << matrix.toString();
    return os;
  
}


#endif /* INVENTORY_MANAGER_H */
