//Given two strings needle and haystack, return the index of the first
//occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
//
// Example 1:
//
//
//Input: haystack = "sadbutsad", needle = "sad"
//Output: 0
//Explanation: "sad" occurs at index 0 and 6.
//The first occurrence is at index 0, so we return 0.
//
//
// Example 2:
//
//
//Input: haystack = "leetcode", needle = "leeto"
//Output: -1
//Explanation: "leeto" did not occur in "leetcode", so we return -1.
//
//
//
// Constraints:
//
//
// 1 <= haystack.length, needle.length <= 10⁴
// haystack and needle consist of only lowercase English characters.
//
//
// Related Topics Two Pointers String String Matching 👍 6654 👎 492


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int localIndex = 0;
        int recentIndex = -1;

        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[localIndex]) {
                if (localIndex == 0) {
                    recentIndex = i;
                }
                if (localIndex == needle.size() - 1) {
                    return recentIndex;
                }

                localIndex++;
            } else {
                if (recentIndex != -1) {
                    i = recentIndex;
                }
                localIndex = 0;
                recentIndex = -1;
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

//Runtime:0 ms, faster than 100.00% of C++ online submissions.
//Memory Usage:8.7 MB, less than 58.81% of C++ online submissions.
