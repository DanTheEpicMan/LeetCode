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
         * Previous char
         * if older position closes, goes down
         * dont delete
         * make list of open positions iterated over
         * 
         * find first close, 
         * loop back until hit open, check for same type, fail/delete, -1 index
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
            //std::cout << s[i] << std::endl;
            if (s[i] == ")"[0] || s[i] == "]"[0] || s[i] == "}"[0]) {
                //std::cout << "ender" << std::endl;
                if (stack.size() == 0 || flip(s[i]) != stack[stack.size()-1]) {
                    return false;
                }
                //std::cout << "flip: " << flip(s[i]) << "stack: " << stack[stack.size()-1] << std::endl;
                s = removeIndexs(s, i-1, i);
                //std::cout << "Removed: " << s << std::endl;
                i -= 1;
                stack.erase( stack.begin() + stack.size() - 1);
                //std::cout << s << std::endl;
            } else if (s[i] == "("[0] || s[i] == "["[0] || s[i] == "{"[0]) {
                stack.push_back(s[i]);
                i++;
            } else {
                return false;
            }
            //std::cout << "end, i:" << i << std::endl;

        }
        return true;


    }

    /*
    from 0 to index, from index + 1 to index2 - index1 - 1, to index2 + 1 to size-index2-1
    a b c d e f g
    0 1 2 3 4 5 6
    */
    string removeIndexs(string s, int in1, int in2) {
        return s.substr(0, in1)  + s.substr(in1+1, in2-in1-1)  + s.substr(in2+1, s.size()-in2-1);
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

