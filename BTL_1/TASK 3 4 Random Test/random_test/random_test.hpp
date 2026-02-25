/*
 * Assignment 1 - Developing List Data Structures and Artificial Neural Networks
 * file : random_test.hpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 10.9.2024
 */
#ifndef RANDOM_TEST_HPP
#define RANDOM_TEST_HPP

#include "../main.hpp"
#include "list/listheader.h"
#include "list/listheader.h"
#include "util/Point.h"
#include "List2D.h"
class RandomTest
{
public:
  RandomTest(int from, int to);

  void runTest();

private:
  void processFile(string inputFilename, string outputFilename);
  void compareOutputs();

  int from;
  int to;

  // ANSI escape codes for colors
  const std::string green = "\033[32m";
  const std::string red = "\033[31m";
  const std::string cyan = "\033[36m";
  const std::string reset = "\033[0m"; // To reset to default color

  bool compareFiles(const std::string &file1, const std::string &file2);

  template <typename T>
  void processList1D(ifstream &inputFile, ofstream &outputFile, List1D<T> *&list)
  {
    list = new List1D<T>();
    string command;
    int line = 2; // Line counter for output

    while (inputFile >> command)
    {
      line++;
      if (command == "init_empty")
      {
        delete list;
        list = new List1D<T>();
      }
      else if (command == "init_num")
      {
        int num_elements;
        inputFile >> num_elements;
        delete list;
        list = new List1D<T>(num_elements);
      }
      else if (command == "init_array")
      {
        int num_elements;
        inputFile >> num_elements;
        T *arr = new T[num_elements];
        for (int i = 0; i < num_elements; i++)
        {
          inputFile >> arr[i];
        }
        delete list;
        list = new List1D<T>(arr, num_elements);
        delete[] arr;
      }
      else if (command == "init_other")
      {
        int num_elements;
        inputFile >> num_elements;
        T *arr = new T[num_elements];
        for (int i = 0; i < num_elements; i++)
        {
          inputFile >> arr[i];
        }
        delete list;
        List1D<T> *temp = new List1D<T>(arr, num_elements);
        list = new List1D<T>(*temp);
        delete temp;
        delete[] arr;
      }
      else if (command == "get")
      {
        int index;
        inputFile >> index;
        try
        {
          if (list)
          {
            T data = list->get(index);
            outputFile << "Line " << line << ": " << data << endl;
          }
        }
        catch (const out_of_range &e)
        {
          outputFile << "Line " << line << ": " << e.what() << endl;
        }
      }
      else if (command == "set")
      {
        int index;
        T value;
        inputFile >> index >> value;
        try
        {
          if (list)
            list->set(index, value);
        }
        catch (const out_of_range &e)
        {
          outputFile << "Line " << line << ": " << e.what() << endl;
        }
      }
      else if (command == "add")
      {
        T value;
        inputFile >> value;
        if (list)
          list->add(value);
      }
      else if (command == "toString")
      {
        if (list)
          outputFile << "Line " << line << ": " << list->toString() << ", size=" << list->size() << endl;
        else
          outputFile << "Empty";
      }
      else if (command == "operator<<")
      {
        if (list)
          outputFile << "Line " << line << ": " << *list << ", size=" << list->size() << endl;
      }
      else
      {
        cerr << "Warning: Unknown command '" << command << "' in file." << endl;
      }
    }
  }

  template <typename T>
  void processList2D(ifstream &inputFile, ofstream &outputFile, List2D<T> *&matrix)
  {
    matrix = new List2D<T>();
    string command;
    int line = 2; // Line counter for output

    while (inputFile >> command)
    {
      line++;
      if (command == "init_empty")
      {
        delete matrix;
        matrix = new List2D<T>();
      }
      else if (command == "init_array")
      {
        int num_rows, num_cols;
        inputFile >> num_rows >> num_cols;
        T value;
        List1D<T> *temp = new List1D<T>[num_rows];

        for (int i = 0; i < num_rows; i++)
        {
          for (int j = 0; j < num_cols; j++)
          {
            inputFile >> value;
            temp[i].add(value);
          }
        }
        delete matrix;
        matrix = new List2D<T>(temp, num_rows);
        delete[] temp;
      }
      else if (command == "init_other")
      {
        int num_rows, num_cols;
        inputFile >> num_rows >> num_cols;
        T value;
        List1D<T> *temp = new List1D<T>[num_rows];

        for (int i = 0; i < num_rows; i++)
        {
          for (int j = 0; j < num_cols; j++)
          {
            inputFile >> value;
            temp[i].add(value);
          }
        }

        delete matrix;
        List2D<T> *newMatrix = new List2D<T>(temp, num_rows);
        matrix = new List2D<T>(*newMatrix);
        delete newMatrix;
        delete[] temp;
      }
      else if (command == "get")
      {
        int rowIndex, colIndex;
        inputFile >> rowIndex >> colIndex;
        try
        {
          T data = matrix->get(rowIndex, colIndex);
          outputFile << "Line " << line << ": " << data << endl;
        }
        catch (const out_of_range &e)
        {
          outputFile << "Line " << line << ": " << e.what() << endl;
        }
      }
      else if (command == "setRow")
      {
        int rowIndex, num_cols;
        inputFile >> rowIndex >> num_cols;
        T *arr = new T[num_cols];
        for (int i = 0; i < num_cols; i++)
        {
          inputFile >> arr[i];
        }
        List1D<T> newRow(arr, num_cols);

        try
        {
          matrix->setRow(rowIndex, newRow);
        }
        catch (const out_of_range &e)
        {
          outputFile << "Line " << line << ": " << e.what() << endl;
        }

        delete[] arr;
      }
      else if (command == "getRow")
      {
        int rowIndex;
        inputFile >> rowIndex;
        try
        {
          List1D<T> row = matrix->getRow(rowIndex);
          outputFile << "Line " << line << ": " << row.toString() << endl;
        }
        catch (const out_of_range &e)
        {
          outputFile << "Line " << line << ": " << e.what() << endl;
        }
      }
      else if (command == "toString")
      {
        outputFile << "Line " << line << ": " << matrix->toString() << endl;
      }
      else if (command == "operator<<")
      {
        outputFile << "Line " << line << ": " << *matrix << endl;
      }
      else
      {
        cerr << "Warning: Unknown command '" << command << "' in file." << endl;
      }
    }
  }
};

#endif // RANDOM_TEST_HPP