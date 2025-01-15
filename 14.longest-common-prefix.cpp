/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string longestPrefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int prefLength = 0;
            for (int j = 0; j < returnLengthSmaller(longestPrefix, strs[i]); j++) {
                if(longestPrefix[j] == strs[i][j]) {
                    prefLength++;
                } else {
                    j = returnLengthSmaller(longestPrefix, strs[i]);
                }
            }
            if (prefLength != 0) {
                longestPrefix = longestPrefix.substr(0, prefLength);
            } else {
                return "";
            }
            
        }

        return longestPrefix;
    }

    int returnLengthSmaller(string a, string b) {
        return (a.size() < b.size()) ? a.size()  : b.size();
    }
};
// @lc code=end

