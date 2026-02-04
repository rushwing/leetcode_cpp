// LeetCode 206. Reverse Linked List (Recursive)
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
// Solution: (Recursive)
//     The recursive approach reverses the list by passing two pointers down the call stack: `current` and `previous`.
//     1. The base case for the recursion is when `current` is `nullptr`. At this point, the entire list has been traversed, and `previous` points to the new head of the reversed list.
//     2. In the recursive step, we save the next node (`current->next`).
//     3. Then, we reverse the pointer of the `current` node to point to `previous`.
//     4. Finally, we make a recursive call with the saved next node as the new `current` and the current node as the new `previous`.
//
// Time Complexity: O(N)
//     - The function visits each node in the list exactly once.
//
// Space Complexity: O(N)
//     - The recursion depth can go up to N, so the call stack will use O(N) space in the worst case (a long list). This is in contrast to the iterative solution's O(1) space complexity.
//
// Pitfalls:
//     - Forgetting the base case (`current == nullptr`) can lead to infinite recursion and a stack overflow.
//     - It's crucial to correctly pass the new `previous` (which is the old `current`) and the new `current` (the saved `next` node) in the recursive call.

#pragma once

#include "common/list_node.h"

namespace leetcode {

using common::ListNode;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return _reverseNode(head, nullptr);
    }

private:
    ListNode* _reverseNode(ListNode* current, ListNode* previous) {
        if (current == nullptr) {
            return previous;
        }

        ListNode* temp = current->next;
        current->next = previous;
        return _reverseNode(temp, current);
    }

};

}  // namespace leetcode