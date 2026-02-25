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

void RandomTest::processFile(string inputFilename, string outputFilename)
{
    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);

    if (!inputFile.is_open())
    {
        cerr << "Error: Cannot open input file " << inputFilename << endl;
        return;
    }
    if (!outputFile.is_open())
    {
        cerr << "Error: Cannot open output file " << outputFilename << endl;
        return;
    }

    string listType, temp, type;
    inputFile >> listType >> temp >> type >> temp; // Read List type and data type

    if (listType == "List1D")
    {
        if (type == "int")
        {
            List1D<int> *list = nullptr;
            processList1D(inputFile, outputFile, list);
            delete list;
        }
        else if (type == "string")
        {
            List1D<string> *list = nullptr;
            processList1D(inputFile, outputFile, list);
            delete list;
        }
        else
        {
            cerr << "Error: Invalid type '" << type << "' in input file." << endl;
        }
    }
    else if (listType == "List2D")
    {
        if (type == "int")
        {
            List2D<int> *matrix = nullptr;
            processList2D(inputFile, outputFile, matrix);
            delete matrix;
        }
        else if (type == "string")
        {
            List2D<string> *matrix = nullptr;
            processList2D(inputFile, outputFile, matrix);
            delete matrix;
        }
        else
        {
            cerr << "Error: Invalid type '" << type << "' in input file." << endl;
        }
    }
    else
    {
        cerr << "Error: Unknown list type '" << listType << "' in input file." << endl;
    }

    inputFile.close();
    outputFile.close();
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
