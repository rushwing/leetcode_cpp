#include <gtest/gtest.h>
#include "solutions/lc_0206_reverse_linked_list_1.h"
#include "common/list_node.h"
#include <vector>

using namespace leetcode;
using common::ListNode;

class ReverseLinkedListTest : public ::testing::Test {
protected:
    Solution solution;

    ListNode* createList(const std::vector<int>& values) {
        if (values.empty()) return nullptr;
        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        for (size_t i = 1; i < values.size(); i++) {
            current->next = new ListNode(values[i]);
            current = current->next;
        }
        return head;
    }

    std::vector<int> toVector(ListNode* head) {
        std::vector<int> result;
        while (head) {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }

    void deleteList(ListNode* head) {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

TEST_F(ReverseLinkedListTest, Example1) {
    // [1,2,3,4,5] -> [5,4,3,2,1]
    ListNode* head = createList({1, 2, 3, 4, 5});
    ListNode* result = solution.reverseList(head);
    EXPECT_EQ(toVector(result), std::vector<int>({5, 4, 3, 2, 1}));
    deleteList(result);
}

TEST_F(ReverseLinkedListTest, Example2) {
    // [1,2] -> [2,1]
    ListNode* head = createList({1, 2});
    ListNode* result = solution.reverseList(head);
    EXPECT_EQ(toVector(result), std::vector<int>({2, 1}));
    deleteList(result);
}

TEST_F(ReverseLinkedListTest, SingleNode) {
    ListNode* head = createList({1});
    ListNode* result = solution.reverseList(head);
    EXPECT_EQ(toVector(result), std::vector<int>({1}));
    deleteList(result);
}

TEST_F(ReverseLinkedListTest, Empty) {
    ListNode* result = solution.reverseList(nullptr);
    EXPECT_EQ(result, nullptr);
}

TEST_F(ReverseLinkedListTest, ThreeNodes) {
    ListNode* head = createList({1, 2, 3});
    ListNode* result = solution.reverseList(head);
    EXPECT_EQ(toVector(result), std::vector<int>({3, 2, 1}));
    deleteList(result);
}
