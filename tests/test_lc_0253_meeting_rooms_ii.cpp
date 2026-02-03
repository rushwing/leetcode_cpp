#include <gtest/gtest.h>
#include "solutions/lc_0253_meeting_rooms_ii_1.h"

using namespace leetcode;

class MeetingRoomsIITest : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(MeetingRoomsIITest, Example1) {
    std::vector<std::vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    EXPECT_EQ(solution.minMeetingRooms(intervals), 2);
}

TEST_F(MeetingRoomsIITest, NoOverlap) {
    std::vector<std::vector<int>> intervals = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_EQ(solution.minMeetingRooms(intervals), 1);
}

TEST_F(MeetingRoomsIITest, FullOverlap) {
    std::vector<std::vector<int>> intervals = {{1, 10}, {2, 9}, {3, 8}};
    EXPECT_EQ(solution.minMeetingRooms(intervals), 3);
}

TEST_F(MeetingRoomsIITest, MixedOverlap) {
    std::vector<std::vector<int>> intervals = {{7, 10}, {2, 4}};
    // Expected output: 1
    EXPECT_EQ(solution.minMeetingRooms(intervals), 1);
}

TEST_F(MeetingRoomsIITest, SingleMeeting) {
    std::vector<std::vector<int>> intervals = {{1, 5}};
    EXPECT_EQ(solution.minMeetingRooms(intervals), 1);
}

TEST_F(MeetingRoomsIITest, EmptyIntervals) {
    std::vector<std::vector<int>> intervals = {};
    EXPECT_EQ(solution.minMeetingRooms(intervals), 0);
}

TEST_F(MeetingRoomsIITest, ComplexCase) {
    std::vector<std::vector<int>> intervals = {{9,10},{4,9},{4,17}};
    EXPECT_EQ(solution.minMeetingRooms(intervals), 2);
}