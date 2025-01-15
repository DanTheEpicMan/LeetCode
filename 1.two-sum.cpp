/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         for (int i = 0; i < nums.size(); i++) { //goes though every number 
            for (int j = 0; j < nums.size(); j++) { //goes through every number per number
                if (nums[i] + nums[j] == target && i != j) {
                    std::vector<int> myVec = { i, j };
                    return myVec;
                }
            }
        }
        return nums;
    }
};
// @lc code=end

