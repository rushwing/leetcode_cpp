# LeetCode C++ Practice

A well-organized C++ project for practicing LeetCode problems and general programming challenges with Google Test.

## Project Structure

```
leetcode_cpp/
├── solutions/            # LeetCode problems (lc_XXXX_name_V.h)
│   ├── lc_0001_two_sum_1.h
│   ├── lc_0056_merge_intervals_1.h
│   ├── lc_0206_reverse_linked_list_1.h
│   └── lc_0283_move_zeroes_1.h
├── practice/             # Non-LeetCode practice problems
│   ├── count_leaf_nodes_1.h
│   └── string_permutations_1.h
├── common/               # Shared data structures
│   ├── list_node.h      # Singly linked list node
│   └── tree_node.h      # Binary tree node
├── tests/                # Test files
│   ├── test_lc_0001_two_sum.cpp
│   └── test_practice_count_leaf_nodes.cpp
├── build/                # Build artifacts (gitignored)
├── CMakeLists.txt        # Build configuration
├── CLAUDE.md             # Comprehensive guide for AI assistants
└── README.md             # This file
```

### Directory Details

**solutions/** - LeetCode problems
- Naming: `lc_XXXX_name_V.h` (e.g., `lc_0001_two_sum_1.h`)
- Versioned for multiple solutions per problem
- Comprehensive documentation with complexity analysis

**practice/** - General practice problems
- Naming: `problem_name_V.h` (e.g., `count_leaf_nodes_1.h`)
- Non-LeetCode problems and exercises

**common/** - Shared data structures
- Reusable structures like ListNode, TreeNode
- Reduces code duplication across problems

## Requirements

- CMake 3.14+
- C++17 compatible compiler (gcc, clang, MSVC)
- Internet connection (first build downloads Google Test)

## Quick Start

```bash
# Clone the repository
cd leetcode_cpp

# Build
mkdir build && cd build
cmake ..
cmake --build .

# Run all tests
ctest --output-on-failure
```

## Adding a New LeetCode Problem

### 1. Create Solution File

Create `solutions/lc_XXXX_problem_name_1.h`:

```cpp
// LeetCode XXXX. Problem Title
// https://leetcode.com/problems/problem-slug/
//
// Tags: Array, Hash Table
//
// Problem:
//     [Problem description from LeetCode]
//
// Solution:
//     - [Your approach]
//
// Time Complexity: O(n)
//     - [Analysis]
//
// Space Complexity: O(1)
//     - [Analysis]
//
// Pitfalls:
//     - [Common mistakes to avoid]

#pragma once

#include <vector>

namespace leetcode {

class Solution {
public:
    returnType methodName(parameters) {
        // Implementation
    }
};

}  // namespace leetcode
```

### 2. Create Test File

Create `tests/test_lc_XXXX_problem_name.cpp`:

```cpp
#include <gtest/gtest.h>
#include "solutions/lc_XXXX_problem_name_1.h"

using namespace leetcode;

class ProblemNameTest : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(ProblemNameTest, Example1) {
    // Test from LeetCode
    EXPECT_EQ(solution.method(input), expected);
}

TEST_F(ProblemNameTest, EdgeCase) {
    // Edge cases
}
```

### 3. Build and Test

```bash
cd build
cmake --build .
ctest --output-on-failure
```

### 4. Commit

```bash
git add solutions/lc_XXXX_problem_name_1.h tests/test_lc_XXXX_problem_name.cpp
git commit -m "feat(solutions): add solution for LC XXXX Problem Name"
```

## Using Common Data Structures

### ListNode (Linked List)

```cpp
#include "common/list_node.h"

namespace leetcode {

using common::ListNode;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Your implementation
    }
};

}  // namespace leetcode
```

### TreeNode (Binary Tree)

```cpp
#include "common/tree_node.h"

namespace leetcode {

using common::TreeNode;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Your implementation
    }
};

}  // namespace leetcode
```

## Multiple Solution Versions

To add an alternative approach for the same problem:

```bash
# Create version 2
cp solutions/lc_0001_two_sum_1.h solutions/lc_0001_two_sum_2.h

# Update documentation to explain the different approach
# Update tests to cover both versions if needed
```

## Running Tests

```bash
# Run all tests
ctest --output-on-failure

# Run specific test suite
ctest -R TwoSumTest --output-on-failure

# Verbose output
ctest --verbose

# Run tests matching pattern
ctest -R "TwoSum|MergeIntervals" --output-on-failure
```

## Project Conventions

### Naming
- **Solution files**: `lc_XXXX_name_V.h` (LeetCode) or `name_V.h` (practice)
- **Test files**: `test_lc_XXXX_name.cpp` (LeetCode) or `test_practice_name.cpp`
- **Classes**: PascalCase (`Solution`, `TreeNode`)
- **Methods**: camelCase (`twoSum`, `maxDepth`)
- **Variables**: snake_case (`left_sum`, `node_count`)

### Namespaces
- LeetCode solutions: `namespace leetcode { ... }`
- Practice problems: `namespace leetcode::practice { ... }`
- Common structures: `namespace leetcode::common { ... }`
- **Never** use `using namespace std;` - always use `std::` prefix

### Documentation
Every solution file must include:
- Problem link and title
- Tags (Array, Tree, DFS, etc.)
- Problem description
- Solution approach explanation
- Time complexity analysis
- Space complexity analysis
- Pitfalls and edge cases

## Example: Complete Solution

**solutions/lc_0001_two_sum_1.h:**
```cpp
// LeetCode 1. Two Sum
// https://leetcode.com/problems/two-sum/
//
// Tags: Array, Hash Table
//
// Problem:
//     Given an array of integers nums and an integer target, return indices of
//     the two numbers such that they add up to target.
//
// Solution:
//     - Use hash table to store each number and its index
//     - For each number, check if complement (target - num) exists
//
// Time Complexity: O(n)
//     - Single pass through array
//
// Space Complexity: O(n)
//     - Hash table stores up to n elements
//
// Pitfalls:
//     - Return indices, not values
//     - Each input has exactly one solution

#pragma once

#include <vector>
#include <unordered_map>

namespace leetcode {

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

}  // namespace leetcode
```

**tests/test_lc_0001_two_sum.cpp:**
```cpp
#include <gtest/gtest.h>
#include "solutions/lc_0001_two_sum_1.h"

using namespace leetcode;

class TwoSumTest : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(TwoSumTest, Example1) {
    std::vector<int> nums = {2, 7, 11, 15};
    auto result = solution.twoSum(nums, 9);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(nums[result[0]] + nums[result[1]], 9);
}

TEST_F(TwoSumTest, Example2) {
    std::vector<int> nums = {3, 2, 4};
    auto result = solution.twoSum(nums, 6);
    EXPECT_EQ(nums[result[0]] + nums[result[1]], 6);
}
```

## Troubleshooting

### Build Fails
```bash
# Clean rebuild
rm -rf build
mkdir build && cd build
cmake ..
cmake --build .
```

### Tests Fail
```bash
# Run with detailed output
ctest --output-on-failure --verbose
```

### Include Errors
- Verify file is in correct directory (solutions/, practice/, common/)
- Check `#include` path matches directory structure
- Ensure CMakeLists.txt hasn't been modified incorrectly

## Additional Resources

- [CLAUDE.md](CLAUDE.md) - Comprehensive guide for AI assistants
- [Google Test Primer](https://google.github.io/googletest/primer.html)
- [LeetCode](https://leetcode.com/)
- [C++ Reference](https://en.cppreference.com/)

## Current Problems

**LeetCode Solutions:**
- LC 1. Two Sum
- LC 56. Merge Intervals
- LC 206. Reverse Linked List
- LC 283. Move Zeroes

**Practice Problems:**
- Count Leaf Nodes (Binary Tree)
- String Permutations (Backtracking)

Total: **46 tests** - All passing ✅
