// LeetCode 0023. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
//
// Tags: Linked List, Divide and Conquer, Heap (Priority Queue), Sorting
//
// Problem:
//     You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//     Merge all the linked-lists into one sorted linked-list and return it.
//
//     Example 1:
//     Input: lists = [[1,4,5],[1,3,4],[2,6]]
//     Output: [1,1,2,3,4,4,5,6]
//     Explanation: The linked-lists are:
//     [
//       1->4->5,
//       1->3->4,
//       2->6
//     ]
//     merging them into one sorted list:
//     1->1->2->3->4->4->5->6
//
//     Example 2:
//     Input: lists = []
//     Output: []
//
//     Example 3:
//     Input: lists = [[]]
//     Output: []
//
// Constraints:
//     - k == lists.length
//     - 0 <= k <= 10^4
//     - 0 <= lists[i].length <= 500
//     - -10^4 <= lists[i][j] <= 10^4
//     - lists[i] is sorted in non-decreasing order
//
// Solution:
//     TODO: Implement the solution
//
// Time Complexity: O(?)
//     - [Detailed analysis]
//
// Space Complexity: O(?)
//     - [Analysis]
//
// Pitfalls:
//     - [Common mistakes to avoid]
//     - [Edge cases to handle]

#pragma once

#include <vector>
#include "common/list_node.h"

namespace leetcode {

using common::ListNode;

class MiniHeap {
public:
    void push(ListNode* node) {
        this->heap.push_back(node);
        _sift_up(this->heap.size() - 1);
    }

    ListNode* pop() {
        if (this->heap.empty()) {
            return nullptr;
        }
        ListNode* root = this->heap[0];
        this->heap[0] = this->heap.back();
        this->heap.pop_back();
        this->_sift_down(0);
        return root;
    }

    ListNode* peak() {
        if (this->heap.empty()) {
            return nullptr;
        }
        return this->heap[0];
    }

    bool empty() {
        return this->heap.empty();
    }

private:
    void _sift_up(int index) {
        if (index <= 0) {
            return;  // Root has no parent
        }
        int parent = (index - 1) / 2;
        if (this->heap[parent]->val <= this->heap[index]->val) {
            return;
        }
        // Swap with parent
        ListNode* temp = this->heap[index];
        this->heap[index] = this->heap[parent];
        this->heap[parent] = temp;
        _sift_up(parent);
    }

    void _sift_down(int index) {
        // If heap is empty or has only one element, nothing to sift down
        if (this->heap.size() <= 1) {
            return;
        }

        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < (int)this->heap.size() && this->heap[left]->val < this->heap[smallest]->val) {
            smallest = left;
        }
        if (right < (int)this->heap.size() && this->heap[right]->val < this->heap[smallest]->val) {
            smallest = right;
        }
        if (smallest == index) {
            return;
        }
        // Swap with smaller child
        ListNode* temp = this->heap[index];
        this->heap[index] = this->heap[smallest];
        this->heap[smallest] = temp;
        _sift_down(smallest);
    }

    std::vector<ListNode*> heap = {};
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* dummy_head = new ListNode(-1);
        ListNode* curr = dummy_head;
        MiniHeap min_heap;
        for (auto list : lists) {
            if (nullptr != list) {
                min_heap.push(list);
            }
        }

        while (!min_heap.empty()) {
            ListNode* node = min_heap.pop();
            curr->next = node;
            curr = curr->next;
            if (nullptr != node->next) {
                min_heap.push(node->next);
            }
        }

        if (nullptr != dummy_head->next) {
            return dummy_head->next;
        }
        return nullptr;
    }
};

}  // namespace leetcode
