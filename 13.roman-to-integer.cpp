/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(std::string s) {


        int number = 0;
           
        //Roman numeral rules:
        // If the number after is bigger, than the list is that number - current number
        //If second number is smaller, is added to current number

        
        for (int i = 0; i < s.length(); i++) {
            if ((s.length() - 1) != i) {
                if (isAhead(s[i], s[i + 1])) {
					number += (RtN(s[i + 1]) - RtN(s[i]));
					i++;
				}
				else {
                    number += RtN(s[i]);
                }
			}
			else {
				number += RtN(s[i]);
			}
        }

    return number;
    }

    int RtN(char roman) { //
        std::vector<char> romanNums = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
        std::vector<int> correspondingNums = { 1, 5, 10, 50, 100, 500, 1000 };

        for (int i = 0; i < romanNums.size(); i++) {
            if (roman == romanNums[i]) {
                return correspondingNums[i];
            }
        }
    }

    bool isAhead(char firstNum, char secondNum) {
        if (RtN(firstNum) < RtN(secondNum)) {
            return true;
        }
        else { return false; }
    }

};
// @lc code=end

