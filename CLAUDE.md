# Claude Code Guide for leetcode_cpp

This document provides comprehensive guidance for Claude Code when working with the leetcode_cpp project.

## Project Structure

```
leetcode_cpp/
├── solutions/            # LeetCode problems (lc_XXXX_name_V.h)
├── practice/             # Non-LeetCode practice problems
├── common/               # Shared data structures (ListNode, TreeNode, etc.)
├── tests/                # Test files
├── build/                # Build artifacts (gitignored)
├── CMakeLists.txt        # Build configuration
├── README.md             # User-facing documentation
├── CLAUDE.md             # This file - AI assistant guidance
└── .gitmessage           # Git commit template
```

### Directory Details

**solutions/**
- Contains LeetCode problem solutions
- Naming: `lc_XXXX_name_V.h` where XXXX is the problem number, name is snake_case, V is version
- Example: `lc_0001_two_sum_1.h`, `lc_0001_two_sum_2.h` (alternate solution)
- Namespace: `namespace leetcode { ... }`

**practice/**
- Contains non-LeetCode practice problems
- Naming: `problem_name_V.h` (no `lc_` prefix)
- Example: `count_leaf_nodes_1.h`, `string_permutations_1.h`
- Namespace: `namespace leetcode::practice { ... }`

**common/**
- Contains shared data structures used across problems
- Example: `list_node.h`, `tree_node.h`
- Namespace: `namespace leetcode::common { ... }`
- Add new common structures here when multiple problems need the same data structure

**tests/**
- LeetCode test files: `test_lc_XXXX_name.cpp`
- Practice test files: `test_practice_problem_name.cpp`
- Uses Google Test framework

## Build and Test Instructions

### Build from Scratch
```bash
cd /Users/danielwong/Dev/leetcode_cpp
rm -rf build
mkdir build
cd build
cmake ..
cmake --build .
```

### Run Tests
```bash
# From build directory
ctest --output-on-failure

# Run specific test
ctest -R TwoSumTest --output-on-failure

# Verbose output
ctest --verbose
```

### Rebuild After Changes
```bash
cd build
cmake --build .
ctest --output-on-failure
```

## Solution File Template

Use this template when creating new LeetCode solution files:

```cpp
// LeetCode XXXX. Problem Title
// https://leetcode.com/problems/problem-slug/
//
// Tags: Array, Hash Table, Two Pointers
//
// Problem:
//     [Full problem description from LeetCode]
//     [Include constraints and examples]
//
// Solution:
//     - [High-level approach]
//     - [Key algorithmic insights]
//     - [Step-by-step explanation]
//
// Time Complexity: O(?)
//     - [Detailed analysis of each operation]
//     - [Overall complexity justification]
//
// Space Complexity: O(?)
//     - [Analysis of auxiliary space used]
//     - [Stack space for recursion if applicable]
//
// Pitfalls:
//     - [Common mistakes to avoid]
//     - [Edge cases to handle]
//     - [Tricky aspects of the problem]

#pragma once

#include <vector>  // Include necessary headers
// #include "common/list_node.h"  // If using common structures

namespace leetcode {

class Solution {
public:
    // Method signature from LeetCode
    returnType methodName(params) {
        // Implementation
    }
};

}  // namespace leetcode
```

## Practice Problem Template

```cpp
// Problem Title
//
// Tags: Tag1, Tag2, Tag3
//
// Problem:
//     [Full problem description]
//
// Solution:
//     - [Approach explanation]
//
// Time Complexity: O(?)
//     - [Analysis]
//
// Space Complexity: O(?)
//     - [Analysis]
//
// Pitfalls:
//     - [Common mistakes]

#pragma once

#include <vector>  // Necessary headers
// #include "common/tree_node.h"  // If needed

namespace leetcode {
namespace practice {

class Solution {
public:
    // Method implementation
};

}  // namespace practice
}  // namespace leetcode
```

## Test File Template

### LeetCode Test Template

```cpp
#include <gtest/gtest.h>
#include "solutions/lc_XXXX_problem_name_1.h"

using namespace leetcode;

class ProblemNameTest : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(ProblemNameTest, Example1) {
    // Test case
    EXPECT_EQ(solution.method(input), expected);
}

TEST_F(ProblemNameTest, EdgeCase) {
    // Edge case
}
```

### Practice Test Template

```cpp
#include <gtest/gtest.h>
#include "practice/problem_name_1.h"

using namespace leetcode::practice;

class ProblemNameTest : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(ProblemNameTest, Example1) {
    EXPECT_EQ(solution.method(input), expected);
}
```

## Common Data Structures

### Using Existing Common Structures

When a solution needs ListNode or TreeNode:

```cpp
#include "common/list_node.h"
// or
#include "common/tree_node.h"

namespace leetcode {

using common::ListNode;  // Or TreeNode
using common::TreeNode;

class Solution {
    // Use ListNode* or TreeNode* in methods
};

}  // namespace leetcode
```

### Adding New Common Structures

When multiple problems need the same data structure:

1. Create `common/structure_name.h`
2. Use namespace `leetcode::common`
3. Update this document with usage instructions

Example:
```cpp
// common/graph_node.h
#pragma once

namespace leetcode {
namespace common {

struct GraphNode {
    int val;
    std::vector<GraphNode*> neighbors;
    GraphNode(int x) : val(x) {}
};

}  // namespace common
}  // namespace leetcode
```

## Git Commit Conventions

### Commit Message Format

Follow the template in `.gitmessage`:

```
<type>(<scope>): <subject>

<WHY>
- Why this change is necessary
- What problem it solves

<WHAT>
- What was changed
- Key implementation details

<TEST>
- How it was tested
- Test results
```

### Types
- `feat`: New feature (new solution, new common structure)
- `fix`: Bug fix
- `refactor`: Code restructuring without behavior change
- `test`: Adding or updating tests
- `docs`: Documentation updates
- `build`: Build system changes

### Scopes
- `solutions`: LeetCode solutions
- `practice`: Practice problems
- `common`: Common data structures
- `tests`: Test files
- `build`: Build configuration

### Examples

```
feat(solutions): add solution for LC 42 Trapping Rain Water

<WHY>
- Solve trapping rain water problem
- Practice two-pointer technique

<WHAT>
- Created lc_0042_trapping_rain_water_1.h
- Implemented two-pointer approach
- Added comprehensive documentation

<TEST>
- Created test_lc_0042_trapping_rain_water.cpp
- All 8 test cases passing
- ctest: 46/46 tests passed

Co-Authored-By: Claude Sonnet 4.5 <noreply@anthropic.com>
```

```
feat(common): add GraphNode data structure

<WHY>
- Multiple graph problems need this structure
- Extract to avoid duplication

<WHAT>
- Created common/graph_node.h
- Used namespace leetcode::common
- Updated CLAUDE.md with usage

<TEST>
- Verified compilation
- Used in LC 133 Clone Graph

Co-Authored-By: Claude Sonnet 4.5 <noreply@anthropic.com>
```

## Coding Conventions

### Namespace Usage
- All solutions: `namespace leetcode { ... }`
- Practice problems: `namespace leetcode::practice { ... }`
- Common structures: `namespace leetcode::common { ... }`
- **Do NOT** use `using namespace std;`
- **DO** use `std::` prefix for standard library types

### Header Guards
- Use `#pragma once` (already C++17 standard)

### Includes
- Standard library: `#include <vector>`
- Common structures: `#include "common/list_node.h"`
- Order: Standard library first, then common structures

### Naming
- Classes: PascalCase (`Solution`)
- Methods: camelCase (`twoSum`, `reverseList`)
- Variables: snake_case (`slow_ptr`, `target_sum`)
- Files: snake_case (`lc_0001_two_sum_1.h`)

### Documentation
- Every solution file MUST have the header comment with:
  - Problem link
  - Tags
  - Problem description
  - Solution approach
  - Time/Space complexity
  - Pitfalls

## Adding a New LeetCode Problem

1. **Create solution file**
   ```bash
   # solutions/lc_XXXX_problem_name_1.h
   ```

2. **Use the solution template** (see above)

3. **Create test file**
   ```bash
   # tests/test_lc_XXXX_problem_name.cpp
   ```

4. **Build and test**
   ```bash
   cd build
   cmake --build .
   ctest --output-on-failure
   ```

5. **Commit**
   ```bash
   git add solutions/lc_XXXX_problem_name_1.h tests/test_lc_XXXX_problem_name.cpp
   git commit
   # Use the commit template
   ```

## Adding a Practice Problem

1. **Create solution file**
   ```bash
   # practice/problem_name_1.h
   ```

2. **Use the practice template**

3. **Create test file**
   ```bash
   # tests/test_practice_problem_name.cpp
   ```

4. **Build, test, and commit** (same as LeetCode problems)

## Adding Multiple Solution Versions

When creating an alternative solution:

1. **Copy existing solution**
   ```bash
   # cp solutions/lc_0001_two_sum_1.h solutions/lc_0001_two_sum_2.h
   ```

2. **Update documentation** in new file to explain the different approach

3. **Update test file** to test both versions (or create separate test file)

4. **Commit** with clear explanation of why the alternative approach is useful

Example test for multiple versions:
```cpp
#include "solutions/lc_0001_two_sum_1.h"
#include "solutions/lc_0001_two_sum_2.h"

namespace v1 = leetcode;
// Would need different namespace for v2

TEST_F(TwoSumTest, Version1_Example1) {
    v1::Solution solution;
    // Test v1
}
```

## Common Pitfalls to Avoid

1. **Forgetting to update CMakeLists.txt**: Not needed! It auto-discovers test files.
2. **Not using std:: prefix**: Always use `std::vector`, not `vector`
3. **Missing documentation**: Every solution needs comprehensive header comments
4. **Wrong namespace**: LeetCode in `leetcode`, practice in `leetcode::practice`
5. **Not testing edge cases**: Always test nullptr, empty arrays, single elements
6. **Not cleaning build**: When CMake changes fail, try `rm -rf build && mkdir build`

## Troubleshooting

### Build Fails
```bash
# Clean rebuild
cd /Users/danielwong/Dev/leetcode_cpp
rm -rf build
mkdir build
cd build
cmake ..
cmake --build .
```

### Tests Fail
```bash
# Run with verbose output
ctest --output-on-failure --verbose

# Run specific test
ctest -R TestName --output-on-failure
```

### Include Errors
- Check that file is in correct directory (solutions/, practice/, common/)
- Verify CMakeLists.txt has all directories in `include_directories()`
- Ensure `#include` path matches directory structure

### Namespace Errors
- LeetCode solutions: `namespace leetcode`
- Practice: `namespace leetcode::practice`
- Common: `namespace leetcode::common`
- In tests: `using namespace leetcode;` or `using namespace leetcode::practice;`

## References

- [Google Test Documentation](https://google.github.io/googletest/)
- [CMake Documentation](https://cmake.org/documentation/)
- [LeetCode](https://leetcode.com/)
- [C++ Reference](https://en.cppreference.com/)
