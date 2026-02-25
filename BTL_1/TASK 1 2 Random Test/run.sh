#!/bin/bash

BUILD_CMD="g++ -fsanitize=address -o main -Iinclude -Isrc -ICode -std=c++17 main.cpp random_test/random_test.cpp src/util/Point.cpp"

echo "Building project TASK1-TASK2 with command:"
echo "$BUILD_CMD"
echo "----------------------------------------"
eval $BUILD_CMD
if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo "----------------------------------------"
    echo "To run tests, use one of the following commands:"
    echo "1. Run tests: ./main test_random number_1 number_2"
    echo "2. Run a specific test: ./main test_random number"
else
    echo "Build failed!"
    exit 1
fi