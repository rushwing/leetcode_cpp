// Count the Leaf Nodes in a Binary Tree
//
// Tags: Tree, DFS, Recursion
//
// Problem:
//     Given a binary tree, count the number of leaf nodes.
//     A leaf node is a node with no children (both left and right are nullptr).
//
// Solution:
//     - Use recursive DFS approach
//     - Base case 1: If root is nullptr, return 0
//     - Base case 2: If root has no children (leaf), return 1
//     - Recursive case: Return sum of leaf counts from left and right subtrees
//
// Time Complexity: O(n)
//     - Visit every node exactly once
//
// Space Complexity: O(h)
//     - Recursion stack depth equals tree height h
//     - In worst case (skewed tree), h = n, so O(n)
//     - In best case (balanced tree), h = log n, so O(log n)
//
// Pitfalls:
//     - Don't forget to check for nullptr root
//     - A leaf has BOTH left and right as nullptr, not just one
//     - Must visit all nodes to count all leaves

#pragma once

#include "common/tree_node.h"

namespace leetcode {
namespace practice {

using common::TreeNode;

class Solution {
public:
    int countLeafNodes(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        if (nullptr == root->left && nullptr == root->right) {
            return 1;
        }
        int left_nodes = countLeafNodes(root->left);
        int right_nodes = countLeafNodes(root->right);
        return left_nodes + right_nodes;
    }
};

}  // namespace practice
}  // namespace leetcode
