/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

/* Accepted
 * 100/100 cases passed (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 83.98 % of cpp submissions (8.5 MB)
*/



// @lc code=start
class Solution {
public:

    bool isValid(string s) {
        /**Plan
         * Get index 0
         * Get opposite of index 0
         * int b, s, c;
         * 
         * 
         * 
         * Examples:
         * (  )  [  ]  {  }
         * 1  0  1  0  1  0
         * b  b  s  s  c  c
         * (  [  ]  )
         * 1  1  0  0
         * b  s  s  b
         * (  [  )  ]
         * 1  1  0  0
         * b  s  b  s
         * (  ]
         * 1  -1
         * b  s
         * (  {  {  }  }  [  ]  )
         * 1  1  2  1  0  1  0  0
         * b  c  c  c  c  s  s  b
         * 
         * index 0-
         * create a list of opens, 
         * check if most recent open matches close
         * delete from list of opens, string does not need to change
         */
        std::vector<char> stack;
        int i = 0;
        if (s.size() % 2 == 1) {return false;}
        while (s.size() > 1) {
            if (s[i] == ")"[0] || s[i] == "]"[0] || s[i] == "}"[0]) {
                if (stack.size() == 0 || flip(s[i]) != stack[stack.size()-1]) {
                    return false;
                }
                s.erase(s.begin() + i-1, s.begin() + i+1);
                i -= 1;
                stack.erase( stack.begin() + stack.size() - 1);
            } else if (s[i] == "("[0] || s[i] == "["[0] || s[i] == "{"[0]) {
                stack.push_back(s[i]);
                i++;
            } else {
                return false;
            }
        }
        return true;


    }

    char flip(char s) {
        if (s == ")"[0]) {
            return "("[0];
        } else if (s == "]"[0]) {
            return "["[0];
        } else {
            return "{"[0];
        }
    }
};
// @lc code=end

