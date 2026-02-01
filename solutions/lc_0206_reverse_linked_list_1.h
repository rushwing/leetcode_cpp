// LeetCode 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/
//
// Tags: Linked List, Recursion
//
// Problem:
//     Given the head of a singly linked list, reverse the list, and return the
//     reversed list.
//
// Solution:
//     - Iterative approach using three pointers: prev, current, next
//     - Start with prev = nullptr, current = head
//     - For each node:
//         1. Save next node
//         2. Reverse current's pointer to point to prev
//         3. Move prev and current one step forward
//     - Return prev (new head) when current becomes nullptr
//
// Time Complexity: O(n)
//     - Single pass through the list
//
// Space Complexity: O(1)
//     - Only using constant extra space for pointers
//
// Pitfalls:
//     - Don't lose reference to the next node before reversing the pointer
//     - Handle empty list (head == nullptr)
//     - Return prev, not current (current will be nullptr at the end)
//     - Alternative recursive solution uses O(n) call stack space

#pragma once

#include "common/list_node.h"

namespace leetcode {

using common::ListNode;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

}  // namespace leetcode
