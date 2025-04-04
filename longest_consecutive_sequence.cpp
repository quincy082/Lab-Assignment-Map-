#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int streak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }
        return longest;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    int result = solution.longestConsecutive(nums);
    cout << "Longest Consecutive Sequence Length: " << result << endl;

    return 0;
}