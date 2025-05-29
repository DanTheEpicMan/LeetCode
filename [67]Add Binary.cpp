//Given two binary strings a and b, return their sum as a binary string.
//
//
// Example 1:
// Input: a = "11", b = "1"
//Output: "100"
//
// Example 2:
// Input: a = "1010", b = "1011"
//Output: "10101"
//
//
// Constraints:
//
//
// 1 <= a.length, b.length <= 10⁴
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.
//
//
// Related Topics Math String Bit Manipulation Simulation 👍 9899 👎 1040


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addBinary(string a, string b) {
        string response = "";
        string longStr = "";
        int shortest = 0;

        int al = a.length();
        int bl = b.length();

        if (al < bl) {
            shortest = al;
            longStr = b;
        } else {
            shortest = bl;
            longStr = a;
        }
        int carryOver = 0;

        for (int i = 0; i < shortest; i++) {
            int anum = (a[al - i-1] == '1') ? 1 : 0;
            int bnum = (b[bl - i-1] == '1') ? 1 : 0;
            int total = anum + bnum + carryOver;
            if (total > 2) {
                carryOver = 1;
                response = '1' + response;
            } else if (total > 1) {
                carryOver = 1;
                response = '0' + response;
            } else if (total > 0) {
                response = '1' + response;
                carryOver = 0;
            } else {
                response = '0' + response;
                carryOver = 0;
            }
        }
        int longStrLength = longStr.length();
        for (int i = shortest; i < longStr.length(); i++) {
            int lnum = (longStr[longStrLength - i-1] == '1') ? 1 : 0;
            int total = lnum + carryOver;
            if (total > 2) {
                carryOver = 1;
                response = '1' + response;
            } else if (total > 1) {
                carryOver = 1;
                response = '0' + response;
            } else if (total > 0) {
                response = '1' + response;
                carryOver = 0;
            } else if (total == 0){
                response = '0' + response;
                carryOver = 0;
            } else {
                response = '0' + response;
                carryOver = 0;
            }
        }
        if (carryOver > 0) {
            response = '1' + response;
        }
        return response;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
