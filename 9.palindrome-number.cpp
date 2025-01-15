/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        std::string strx = std::to_string(x);

        int length = strx.length() -1;

        for (int i = 0; i < length; i++) {
            if (strx[i] != strx[length - i]) {
                return false;
            }
        }
        return true;

    }
};
// @lc code=end

