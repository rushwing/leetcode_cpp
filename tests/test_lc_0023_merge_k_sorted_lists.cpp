#include <gtest/gtest.h>
#include "solutions/lc_0023_merge_k_sorted_lists_1.h"
#include "common/list_node.h"

using namespace leetcode;

using common::ListNode;

class MergeKSortedListsTest : public ::testing::Test {
protected:
    Solution solution;

    // Helper function to create a linked list from a vector
    ListNode* createList(const std::vector<int>& values) {
        if (values.empty()) {
            return nullptr;
        }
        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        for (size_t i = 1; i < values.size(); ++i) {
            current->next = new ListNode(values[i]);
            current = current->next;
        }
        return head;
    }

    // Helper function to convert linked list to vector
    std::vector<int> listToVector(ListNode* head) {
        std::vector<int> result;
        while (head != nullptr) {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }

    // Helper to free linked list memory
    void freeList(ListNode* head) {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~MergeKSortedListsTest() override = default;
};

TEST_F(MergeKSortedListsTest, Example1) {
    std::vector<ListNode*> lists = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})
    };
    ListNode* result = solution.mergeKLists(lists);
    EXPECT_EQ(listToVector(result), std::vector<int>({1, 1, 2, 3, 4, 4, 5, 6}));
    freeList(result);
    // Note: nodes from lists are now part of result, no need to free separately
}

TEST_F(MergeKSortedListsTest, EmptyInput) {
    std::vector<ListNode*> lists = {};
    ListNode* result = solution.mergeKLists(lists);
    EXPECT_EQ(result, nullptr);
}

TEST_F(MergeKSortedListsTest, EmptyLists) {
    std::vector<ListNode*> lists = {nullptr, nullptr, nullptr};
    ListNode* result = solution.mergeKLists(lists);
    EXPECT_EQ(result, nullptr);
}

TEST_F(MergeKSortedListsTest, SingleList) {
    std::vector<ListNode*> lists = {
        createList({1, 2, 3})
    };
    ListNode* result = solution.mergeKLists(lists);
    EXPECT_EQ(listToVector(result), std::vector<int>({1, 2, 3}));
    freeList(result);
    // Note: lists[0]'s nodes are now part of result, no need to free separately
}

TEST_F(MergeKSortedListsTest, SingleElementLists) {
    std::vector<ListNode*> lists = {
        createList({1}),
        createList({2}),
        createList({3})
    };
    ListNode* result = solution.mergeKLists(lists);
    EXPECT_EQ(listToVector(result), std::vector<int>({1, 2, 3}));
    freeList(result);
    // Note: nodes from lists are now part of result, no need to free separately
}

TEST_F(MergeKSortedListsTest, AllSameElements) {
    std::vector<ListNode*> lists = {
        createList({1, 1, 1}),
        createList({1, 1, 1})
    };
    ListNode* result = solution.mergeKLists(lists);
    EXPECT_EQ(listToVector(result), std::vector<int>({1, 1, 1, 1, 1, 1}));
    freeList(result);
    // Note: nodes from lists are now part of result, no need to free separately
}

TEST_F(MergeKSortedListsTest, MixedEmptyAndNonEmpty) {
    std::vector<ListNode*> lists = {
        createList({1, 3, 5}),
        nullptr,
        createList({2, 4, 6})
    };
    ListNode* result = solution.mergeKLists(lists);
    EXPECT_EQ(listToVector(result), std::vector<int>({1, 2, 3, 4, 5, 6}));
    freeList(result);
    // Note: nodes from lists are now part of result, no need to free separately
}

TEST_F(MergeKSortedListsTest, NegativeValues) {
    std::vector<ListNode*> lists = {
        createList({-10, -5, 0}),
        createList({-7, -3, 2})
    };
    ListNode* result = solution.mergeKLists(lists);
    EXPECT_EQ(listToVector(result), std::vector<int>({-10, -7, -5, -3, 0, 2}));
    freeList(result);
    // Note: nodes from lists are now part of result, no need to free separately
}
