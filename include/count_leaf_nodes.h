#pragma once

// Count the Leaf Nodes in a Binary Tree
// A leaf node is a node with no children (both left and right are nullptr)

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countLeafNodes(TreeNode* root) {
        int totalLeaves = 0;

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
