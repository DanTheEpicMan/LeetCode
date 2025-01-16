/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        /**Plan
         * Find out that even
         * Loop through string to find an end to index 0,
         * then delete both
         * reloop
         * 
         * RERUN:
         * find index 0
         * find opposite of index 0, if cant, return false
         * loop until you find opposite
         * delete 0 and found
         */
        while (s.size() > 1) {
           

        }
        return true;
    }

    string flip(char s) {
        if (s == "("[0]) {
            return ")";
        } else if (s == "["[0]) {
            return "]";
        } else {
            return "}";
        }
    }
};
// @lc code=end

