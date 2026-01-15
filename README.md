# LeetCode C++ Practice

A C++ project for practicing LeetCode problems with Google Test.

## Project Structure

```
leetcode_cpp/
├── CMakeLists.txt
├── include/          # Solution header files
│   └── 0001_two_sum.h
├── tests/            # Test files
│   └── test_0001_two_sum.cpp
└── src/              # (Optional) For complex solutions
```

## Requirements

- CMake 3.14+
- C++17 compatible compiler

## Build & Run Tests

```bash
# Create build directory
mkdir build && cd build

# Configure
cmake ..

# Build
cmake --build .

# Run tests
ctest --output-on-failure
```

## Adding New Problems

1. Create a header file in `include/` (e.g., `include/0002_problem_name.h`)
2. Create a test file in `tests/` (e.g., `tests/test_0002_problem_name.cpp`)
3. Rebuild and run tests

## Example Workflow

```cpp
// include/0344_reverse_string.h
#pragma once
#include <string>
#include <algorithm>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        std::reverse(s.begin(), s.end());
    }
};
```

```cpp
// tests/test_0344_reverse_string.cpp
#include <gtest/gtest.h>
#include "0344_reverse_string.h"

TEST(ReverseStringTest, Example1) {
    Solution solution;
    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    std::vector<char> expected = {'o', 'l', 'l', 'e', 'h'};
    solution.reverseString(s);
    EXPECT_EQ(s, expected);
}
```
