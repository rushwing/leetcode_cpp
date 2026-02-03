// LeetCode 146. LRU Cache
// https://leetcode.com/problems/lru-cache/
//
// Tags: Hash Table, Linked List, Design, Doubly-Linked List
//
// Problem:
//     Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
//
//     Implement the LRUCache class:
//     - LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//     - int get(int key) Return the value of the key if the key exists, otherwise return -1.
//     - void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
//
//     The functions get and put must each run in O(1) average time complexity.
//
//     Example 1:
//     Input
//     ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//     [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//     Output
//     [null, null, null, 1, null, -1, null, -1, 3, 4]
//
//     Explanation
//     LRUCache lRUCache = new LRUCache(2);
//     lRUCache.put(1, 1); // cache is {1=1}
//     lRUCache.put(2, 2); // cache is {1=1, 2=2}
//     lRUCache.get(1);    // return 1
//     lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
//     lRUCache.get(2);    // returns -1 (not found)
//     lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
//     lRUCache.get(1);    // return -1 (not found)
//     lRUCache.get(3);    // return 3
//     lRUCache.get(4);    // return 4
//
//     Constraints:
//     - 1 <= capacity <= 3000
//     - 0 <= key <= 10^4
//     - 0 <= value <= 10^5
//     - At most 2 * 10^5 calls will be made to get and put.
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

#include <unordered_map>

namespace leetcode {

class LinkedNode {
public:
    int key;
    int value;
    LinkedNode* prev;
    LinkedNode* next;
    LinkedNode(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};


class LRUCache {
public:
    int capacity;
    std::unique_ptr<LinkedNode> head;
    std::unique_ptr<LinkedNode> tail;
    std::unordered_map<int, LinkedNode*> cache;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = std::make_unique<LinkedNode>(-1, -1);
        this->tail = std::make_unique<LinkedNode>(-1, -1);
        this->head->next = this->tail.get();
        this->tail->prev = this->head.get();
    }

    ~LRUCache() {
        for (auto& [key, node] : cache) {
            delete node;
        }
        cache.clear();
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        LinkedNode* node = cache[key];
        this->moveToLast(node);

        return node->value; 
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // 更新node的value，并更新位置到tail->prev和tail之间
            LinkedNode* node = cache[key];
            node->value = value;
            this->moveToLast(node);
            return;
        }

        if (cache.size() >= this->capacity) {
            // 删除head->next节点
            auto head = this->head.get();
            auto old_first = head->next;
            head->next = old_first->next;
            old_first->next->prev = head;
            cache.erase(old_first->key);
            // 释放内存
            delete old_first;
        }
        auto tail = this->tail.get();
        auto old_last = tail->prev;
        LinkedNode* new_node = new LinkedNode(key, value);
        // 插入new_node到tail->prev和tail之间
        old_last->next = new_node;
        new_node->prev = old_last;
        new_node->next = tail;
        tail->prev = new_node;
        // 将new_node加入cache
        cache[key] = new_node;
    }

private:
    void moveToLast(LinkedNode* node) {
        // 断开node的[old_prev]和[old_next]，取出原始node，并重新链接[old_prev]和[old_next]
        auto old_prev = node->prev;
        auto old_next = node->next;
        old_prev->next = old_next;
        old_next->prev = old_prev;

        // 将node插入到tail->prev和tail之间
        auto tail = this->tail.get();
        auto old_last = tail->prev;
        old_last->next = node;
        node->prev = old_last;
        node->next = tail;
        tail->prev = node;
    }
};

}  // namespace leetcode