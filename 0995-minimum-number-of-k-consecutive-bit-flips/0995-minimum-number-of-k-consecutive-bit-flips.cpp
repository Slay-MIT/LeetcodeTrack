class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // Keeps track of flipped states
        vector<bool> flipped(nums.size(), false);
        // Tracks valid flips within the past window
        int validFlipsFromPastWindow = 0;
        // Counts total flips needed
        int flipCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                // Decrease count of valid flips from the past window if needed
                if (flipped[i - k]) {
                    validFlipsFromPastWindow--;
                }
            }

            // Check if current bit needs to be flipped
            if (validFlipsFromPastWindow % 2 == nums[i]) {
                // If flipping the window extends beyond the array length,
                // return -1
                if (i + k > nums.size()) {
                    return -1;
                }
                // Increment the count of valid flips and mark current as
                // flipped
                validFlipsFromPastWindow++;
                flipped[i] = true;
                flipCount++;
            }
        }

        return flipCount;
    }
};


// class Solution {
// public:
//     int minKBitFlips(vector<int>& nums, int k) {
//         int n = nums.size();
//         // Queue to keep track of flips
//         deque<int> flipQueue;
//         // Current flip state
//         int flipped = 0;
//         // Total number of flips
//         int result = 0;

//         for (int i = 0; i < n; ++i) {
//             // Remove the effect of the oldest flip if it's out of the current
//             // window
//             if (i >= k) {
//                 flipped ^= flipQueue.front();
//                 flipQueue.pop_front();
//             }

//             // If the current bit is 0 it needs to be flipped
//             if (flipped == nums[i]) {
//                 // If we cannot flip a subarray starting at index i
//                 if (i + k > n) {
//                     return -1;
//                 }
//                 // Add a flip at this position
//                 flipQueue.push_back(1);
//                 // Toggle the flipped state
//                 flipped ^= 1;
//                 // Increment the flip count
//                 result += 1;
//             } else {
//                 flipQueue.push_back(0);
//             }
//         }

//         return result;
//     }
// };

// class Solution {
// public:
//     int minKBitFlips(vector<int>& nums, int k) {
//         // Tracks the current number of flips
//         int currentFlips = 0;
//         // Tracks the total number of flips
//         int totalFlips = 0;

//         for (int i = 0; i < nums.size(); ++i) {
//             // If the window slides out of the range and the leftmost element
//             // is marked as flipped (2), decrement currentFlips
//             if (i >= k && nums[i - k] == 2) {
//                 currentFlips--;
//             }

//             // Check if the current bit needs to be flipped
//             if ((currentFlips % 2) == nums[i]) {
//                 // If flipping would exceed array bounds, return -1
//                 if (i + k > nums.size()) {
//                     return -1;
//                 }
//                 // Mark the current bit as flipped
//                 nums[i] = 2;
//                 currentFlips++;
//                 totalFlips++;
//             }
//         }

//         return totalFlips;
//     }
// };


// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/editorial