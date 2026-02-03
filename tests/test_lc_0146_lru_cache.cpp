#include <gtest/gtest.h>
#include "solutions/lc_0146_lru_cache_1.h"

using namespace leetcode;

class LRUCacheTest : public ::testing::Test {
protected:
    // No common setup needed for these tests,
    // as each test requires a cache with a specific capacity.
};

TEST_F(LRUCacheTest, Example1) {
    // Following the sequence from LeetCode Example 1
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    EXPECT_EQ(lRUCache.get(1), 1);    // return 1, cache becomes {2=2, 1=1}
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    EXPECT_EQ(lRUCache.get(2), -1);   // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {3=3, 4=4}
    EXPECT_EQ(lRUCache.get(1), -1);   // return -1 (not found)
    EXPECT_EQ(lRUCache.get(3), 3);    // return 3, cache becomes {4=4, 3=3}
    EXPECT_EQ(lRUCache.get(4), 4);    // return 4, cache becomes {3=3, 4=4}
}

TEST_F(LRUCacheTest, GetUpdatesRecency) {
    LRUCache cache(3);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3); // Cache: [1, 2, 3] (LRU -> MRU)
    
    cache.get(1); // Access 1, making it MRU. Cache should be ordered [2, 3, 1]
    
    cache.put(4, 4); // Evicts 2 (the LRU element). Cache becomes [3, 1, 4]
    
    EXPECT_EQ(cache.get(2), -1); // 2 should be evicted
    EXPECT_EQ(cache.get(1), 1);
}

TEST_F(LRUCacheTest, PutUpdatesExistingValue) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2); // Cache: [1, 2]
    
    cache.put(1, 10); // Update value of 1 and make it MRU. Cache: [2, 1]
    
    EXPECT_EQ(cache.get(1), 10);
    
    cache.put(3, 3); // Evicts 2. Cache: [1, 3]
    EXPECT_EQ(cache.get(2), -1);
}

TEST_F(LRUCacheTest, CapacityOne) {
    LRUCache cache(1);
    cache.put(1, 1);
    EXPECT_EQ(cache.get(1), 1);
    
    cache.put(2, 2); // Evicts 1
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(2), 2);
}

TEST_F(LRUCacheTest, GetNonExistent) {
    LRUCache cache(2);
    cache.put(1, 1);
    EXPECT_EQ(cache.get(2), -1);
}