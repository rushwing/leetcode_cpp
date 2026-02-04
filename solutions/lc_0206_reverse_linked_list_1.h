// LeetCode 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/
//
// Tags: Linked List, Recursion
//
// Problem:
//     Given the head of a singly linked list, reverse the list, and return the reversed list.
//
//     Example 1:
//     Input: head = [1,2,3,4,5]
//     Output: [5,4,3,2,1]
//
//     Example 2:
//     Input: head = [1,2]
//     Output: [2,1]
//
//     Example 3:
//     Input: head = []
//     Output: []
//
//     Constraints:
//     - The number of nodes in the list is in the range [0, 5000].
//     - -5000 <= Node.val <= 5000
//
// Solution:
//     - [To be implemented]
//
// Time Complexity: O(?)
//     - [To be analyzed]
//
// Space Complexity: O(?)
//     - [To be analyzed]
//
// Pitfalls:
//     - [To be identified]

#pragma once

#include "common/list_node.h"

namespace leetcode {

using common::ListNode;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

}  // namespace leetcode