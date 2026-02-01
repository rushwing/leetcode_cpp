#include <gtest/gtest.h>
#include "practice/count_leaf_nodes_1.h"
#include "common/tree_node.h"

using namespace leetcode::practice;
using leetcode::common::TreeNode;

class CountLeafNodesTest : public ::testing::Test {
protected:
    Solution solution;

    // Helper to build a tree and manage memory
    std::vector<TreeNode*> nodes;

    TreeNode* createNode(int val) {
        TreeNode* node = new TreeNode(val);
        nodes.push_back(node);
        return node;
    }

    void TearDown() override {
        for (auto node : nodes) {
            delete node;
        }
        nodes.clear();
    }
};

TEST_F(CountLeafNodesTest, NullTree) {
    EXPECT_EQ(solution.countLeafNodes(nullptr), 0);
}

TEST_F(CountLeafNodesTest, SingleNode) {
    TreeNode* root = createNode(1);
    EXPECT_EQ(solution.countLeafNodes(root), 1);
}

TEST_F(CountLeafNodesTest, TwoLeaves) {
    //       1
    //      / \
    //     2   3
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    EXPECT_EQ(solution.countLeafNodes(root), 2);
}

TEST_F(CountLeafNodesTest, ThreeLeaves) {
    //       1
    //      / \
    //     2   3
    //    /
    //   4
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    EXPECT_EQ(solution.countLeafNodes(root), 2);
}

TEST_F(CountLeafNodesTest, LeftSkewedTree) {
    //   1
    //  /
    // 2
    //  \
    //   3
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->left->right = createNode(3);
    EXPECT_EQ(solution.countLeafNodes(root), 1);
}

TEST_F(CountLeafNodesTest, CompleteTree) {
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    EXPECT_EQ(solution.countLeafNodes(root), 4);
}
