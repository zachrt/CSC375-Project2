# 1. Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# 2. Name your project and specify the language
project(TreeCalculator VERSION 1.0 LANGUAGES CXX)

# 3. Specify the C++ standard (C++11 is usually sufficient, but 17 is modern)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 4. Tell CMake to create an executable using your source files.
# You only need to compile the .cpp files. 
# (You don't compile .h files directly, they are included by the .cpp files).
add_executable(Calculator 
    main.cpp 
    ExpressionTree.h
    ExpressionTree.cpp
    Stack.h
    TreeNode.h
)