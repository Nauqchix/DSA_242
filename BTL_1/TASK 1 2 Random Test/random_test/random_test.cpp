/*
 * Assignment 1 - Developing List Data Structures and Artificial Neural Networks
 * file : random_test.cpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 10.9.2024
 */
#include "random_test.hpp"

struct Task1
{
  int number_line, capacity;
  string skip, _iList, _type, _itemEqual, _deleteUserData;
};

RandomTest::RandomTest(int from, int to) : from(from), to(to) {}

void RandomTest::runTest()
{
  for (int i = from; i <= to; ++i)
  {
    std::string inputFilename =
        "random_test/input/input_" + std::to_string(i);
    std::string outputFilename =
        "random_test/output/output_" + std::to_string(i);
    // "random_test/expected/expected_" + std::to_string(i);
    processFile(inputFilename, outputFilename);
  }

  compareOutputs();
}
template <class T>
void RandomTest::runtime(
    IList<T> &list, std::ifstream &file, string outputFilename, string _iList,
    string _type, void (*deleteUserData)(T),
    std::map<std::string, string (*)(T &)> function_point2str)
{
  int number_line = 6;
  std::string command;
  std::ofstream outFile(outputFilename);
  if (!outFile)
  {
    std::cerr << "Error opening output file: " << outputFilename << '\n';
    return;
  }

  T value;
  int index;
  string str;
  while (file >> command)
  {
    outFile << "line " << number_line << ": ";
    if (command == "add")
    {
      file >> value;
      outFile << command << " " << value << '\n';

      list.add(value); //! code
    }
    else if (command == "add_index")
    {
      file >> index >> value;
      outFile << command << " " << index << " " << value << '\n';

      try
      {
        list.add(index, value); //! code
      }
      catch (const std::out_of_range &e)
      {
        if (deleteUserData)
          deleteUserData(value);
        outFile << "Error: Out of range exception: " + string(e.what()) << '\n';
      }
    }
    else if (command == "removeAt")
    {
      file >> index;
      outFile << command << " " << index << '\n';

      try
      {
        T result = list.removeAt(index); //! code
        outFile << "Result: " << result << endl;
        if (deleteUserData)
          deleteUserData(result);
      }
      catch (const std::out_of_range &e)
      {
        outFile << "Error: Out of range exception: " + string(e.what()) << '\n';
      }
    }
    else if (command == "removeItem")
    {
      file >> value >> str;
      outFile << command << " " << value << " " << str << '\n';
      if (str == "null")
      {
        bool result = list.removeItem(value); //! code
        outFile << "Result: " << (result ? "true" : "false") << endl;
      }
      else
      {
        bool result = list.removeItem(value, deleteUserData); //! code
        outFile << "Result: " << (result ? "true" : "false") << endl;
      }

      if (deleteUserData)
        deleteUserData(value);
    }
    else if (command == "clear")
    {
      outFile << command << '\n';
      list.clear();
    }
    else if (command == "get")
    {
      file >> index;
      outFile << command << " " << index << '\n';

      try
      {
        T result = list.get(index); //! code
        outFile << "Result: " << result << endl;
      }
      catch (const std::out_of_range &e)
      {
        outFile << "Error: Out of range exception: " + string(e.what()) << '\n';
      }
    }
    else if (command == "indexOf")
    {
      file >> value;
      outFile << command << " " << value << '\n';

      int result = list.indexOf(value); //! code
      outFile << "Result: " << result << endl;
      if (deleteUserData)
        deleteUserData(value);
    }
    else if (command == "contains")
    {
      file >> value;
      outFile << command << " " << value << '\n';

      bool result = list.contains(value); //! code
      outFile << "Result: " << (result ? "true" : "false") << endl;
      if (deleteUserData)
        deleteUserData(value);
    }
    else if (command == "print_item2str")
    {
      file >> str;
      outFile << command << " " << str << '\n';
      if (function_point2str.empty())
      {
        outFile << "size:" << list.size() << ";empty:" << list.empty()
                << ";str=" << list.toString() << endl;
      }
      else
      {
        outFile << "size:" << list.size() << ";empty:" << list.empty()
                << ";str=" << list.toString(function_point2str[str]) << endl;
      }
    }
    else if (command == "operator=")
    {
      outFile << command << '\n';
      if (_iList == "DLinkedList")
      {
        DLinkedList<T> dList = dynamic_cast<DLinkedList<T> &>(list);
        dList.setDeleteUserDataPtr(0);
        outFile << "size:" << dList.size() << ";empty:" << dList.empty()
                << ";str=" << dList.toString() << endl;
      }
      else
      {
        XArrayList<T> xList = dynamic_cast<XArrayList<T> &>(list);
        xList.setDeleteUserDataPtr(0);
        outFile << "size:" << xList.size() << ";empty:" << xList.empty()
                << ";str=" << xList.toString() << endl;
      }
    }
    else if (command == "contructor")
    {
      outFile << command << '\n';
      if (_iList == "DLinkedList")
      {
        DLinkedList<T> dList(dynamic_cast<DLinkedList<T> &>(list));
        dList.setDeleteUserDataPtr(0);
        outFile << "size:" << dList.size() << ";empty:" << dList.empty()
                << ";str=" << dList.toString() << endl;
      }
      else
      {
        XArrayList<T> xList(dynamic_cast<XArrayList<T> &>(list));
        xList.setDeleteUserDataPtr(0);
        outFile << "size:" << xList.size() << ";empty:" << xList.empty()
                << ";str=" << xList.toString() << endl;
      }
    }
    else if (command == "Iterator_for")
    {
      outFile << command << '\n';
      if (_iList == "DLinkedList")
      {
        DLinkedList<T> dList(dynamic_cast<DLinkedList<T> &>(list));
        dList.setDeleteUserDataPtr(0);
        for (auto i : dList)
        {
          outFile << i << " ";
        }
        outFile << endl;
      }
      else
      {
        XArrayList<T> xList(dynamic_cast<XArrayList<T> &>(list));
        xList.setDeleteUserDataPtr(0);
        for (auto i : xList)
        {
          outFile << i << " ";
        }
        outFile << endl;
      }
    }
    else if (command == "BWDIterator_for")
    {
      outFile << command << '\n';
      if (_iList == "DLinkedList")
      {
        DLinkedList<T> dList(dynamic_cast<DLinkedList<T> &>(list));
        dList.setDeleteUserDataPtr(0);
        for (auto it = dList.bbegin(); it != dList.bend(); --it)
        {
          if (it != dList.bbegin())
            outFile << ", ";
          outFile << *it;
        }
        outFile << endl;
      }
      else
      {
        XArrayList<T> xList(dynamic_cast<XArrayList<T> &>(list));
        xList.setDeleteUserDataPtr(0);
        for (auto i : xList)
        {
          outFile << i << " ";
        }
        outFile << endl;
      }
    }
    else
    {
      outFile << "end test ---- VO TIEN ----";
    }

    number_line++;
  }

  outFile.close(); // Đóng file sau khi hoàn thành
}

void RandomTest::processFile(string inputFilename, string outputFilename)
{
  std::ifstream file(inputFilename);
  int number_line, capacity;
  // Check if the file was successfully opened
  if (!file.is_open())
  {
    cerr << "Error: Could not open file " << inputFilename << endl;
    return;
  }

  string skip, _iList, _type, _itemEqual, _deleteUserData;
  file >> number_line >> skip >> _iList >> skip >> _type;
  file >> skip >> skip >> _itemEqual;
  file >> skip >> skip >> _deleteUserData;
  file >> skip >> skip >> capacity >> skip;

  std::map<std::string, string (*)(Point &)> function_point2str;
  function_point2str["null"] = 0;
  function_point2str["point2str_X"] = &Point::point2str_X;
  function_point2str["point2str_Y"] = &Point::point2str_Y;
  function_point2str["point2str_Z"] = &Point::point2str_Z;
  function_point2str["point2str"] = &Point::point2str;

  std::map<std::string, string (*)(Point *&)> function_point2str_str;
  function_point2str_str["null"] = 0;
  function_point2str_str["point2str_X"] = &Point::point2str_X;
  function_point2str_str["point2str_Y"] = &Point::point2str_Y;
  function_point2str_str["point2str_Z"] = &Point::point2str_Z;
  function_point2str_str["point2str"] = &Point::point2str;

  std::map<std::string, bool (*)(Point &, Point &)> function_itemEqual;
  function_itemEqual["null"] = 0;
  function_itemEqual["pointEQ_X"] = &Point::pointEQ_X;
  function_itemEqual["pointEQ_Y"] = &Point::pointEQ_Y;
  function_itemEqual["pointEQ_Z"] = &Point::pointEQ_Z;
  function_itemEqual["pointEQ"] = &Point::pointEQ;

  std::map<std::string, bool (*)(Point *&, Point *&)> function_itemEqual_ptr;
  function_itemEqual_ptr["null"] = 0;
  function_itemEqual_ptr["pointEQ_X"] = &Point::pointEQ_X;
  function_itemEqual_ptr["pointEQ_Y"] = &Point::pointEQ_Y;
  function_itemEqual_ptr["pointEQ_Z"] = &Point::pointEQ_Z;
  function_itemEqual_ptr["pointEQ"] = &Point::pointEQ;
  if (_iList == "XArrayList")
  {
    if (_type == "string")
    {
      XArrayList<std::string> list(0, 0, capacity);
      this->runtime(list, file, outputFilename, _iList, _type);
    }
    else if (_type == "int")
    {
      XArrayList<int> list(0, 0, capacity);
      this->runtime(list, file, outputFilename, _iList, _type);
    }
    else if (_type == "bool")
    {
      XArrayList<bool> list(0, 0, capacity);
      this->runtime(list, file, outputFilename, _iList, _type);
    }
    else if (_type == "Point")
    {
      XArrayList<Point> list(0, function_itemEqual[_itemEqual], capacity);
      this->runtime(list, file, outputFilename, _iList, _type,
                    &Point::pointRemove, function_point2str);
    }
    else if (_type == "Point*")
    {
      XArrayList<Point *> list(&XArrayList<Point *>::free,
                               function_itemEqual_ptr[_itemEqual], capacity);
      this->runtime(list, file, outputFilename, _iList, _type,
                    &Point::pointRemove, function_point2str_str);
    }
  }
  else if (_iList == "DLinkedList")
  {
    if (_type == "string")
    {
      DLinkedList<std::string> list(0, 0);
      this->runtime(list, file, outputFilename, _iList, _type);
    }
    else if (_type == "int")
    {
      DLinkedList<int> list(0, 0);
      this->runtime(list, file, outputFilename, _iList, _type);
    }
    else if (_type == "bool")
    {
      DLinkedList<bool> list(0, 0);
      this->runtime(list, file, outputFilename, _iList, _type);
    }
    else if (_type == "Point")
    {
      DLinkedList<Point> list(0, function_itemEqual[_itemEqual]);
      this->runtime(list, file, outputFilename, _iList, _type,
                    &Point::pointRemove, function_point2str);
    }
    else if (_type == "Point*")
    {
      DLinkedList<Point *> list(&DLinkedList<Point *>::free,
                                function_itemEqual_ptr[_itemEqual]);
      this->runtime(list, file, outputFilename, _iList, _type,
                    &Point::pointRemove, function_point2str_str);
    }
  }
}

void RandomTest::compareOutputs()
{
  std::vector<std::string> fails;
  int totalTests = 0;

  for (int i = from; i <= to; ++i)
  {
    std::string outputFile =
        "random_test/output/output_" + std::to_string(i);
    std::string expectedFile =
        "random_test/expected/expected_" + std::to_string(i);

    try
    {
      bool result = compareFiles(outputFile, expectedFile);
      if (result)
      {
        // Print pass message if files match
        std::cout << green << "Test input_" << i << " --------------- PASS"
                  << reset << "\n";
      }
      else
      {
        // Print fail message if files don't match
        fails.push_back("input_" + std::to_string(i));
        std::cout << red << "Test input_" << i << " --------------- FAIL"
                  << reset << "\n";
      }
      ++totalTests;
    }
    catch (const std::runtime_error &e)
    {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }

  std::cout << cyan << "\nResult -------------------------" << reset
            << std::endl;
  if (fails.empty())
  {
    std::cout << green << "All tests passed!" << reset << std::endl;
  }
  else
  {
    int failedTests = fails.size();
    int passedTests = totalTests - failedTests;
    double passRate =
        (totalTests > 0)
            ? (static_cast<double>(passedTests) / totalTests) * 100.0
            : 0.0;

    std::cout << red << "Some tests failed:";
    for (const auto &fail : fails)
    {
      std::cout << "  " << fail;
    }
    std::cout << cyan << "\nPass rate: " << passRate << "%" << reset
              << std::endl;
  }
}

bool RandomTest::compareFiles(const std::string &file1,
                              const std::string &file2)
{
  std::ifstream f1(file1);
  std::ifstream f2(file2);

  if (!f1.is_open() || !f2.is_open())
  {
    throw std::runtime_error("Could not open files for comparison.");
  }

  std::stringstream buffer1, buffer2;
  buffer1 << f1.rdbuf();
  buffer2 << f2.rdbuf();
  return buffer1.str() == buffer2.str();
}
