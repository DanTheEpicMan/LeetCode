#include <iostream>
#include <string>
#include <vector>

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

class Solution {
public:
    int romanToInt(std::string s) {


        int number = 0;
           
        //Roman numeral rules:
        // If the number after is bigger, than the list is that number - current number
        //If second number is smaller, is added to current number

        
        for (int i = 0; i < s.length(); i++) {
            if ((s.length() - 1) != i) {
				std::cout << "We are not at the end of the string\n";
                if (isAhead(s[i], s[i + 1])) {
					std::cout << "Is ahead with numbers:" << s[i] << " and " << s[i + 1] << std::endl;
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
        std::cout << "if " << firstNum << " is ahead of " << secondNum << "\n";
        if (RtN(firstNum) < RtN(secondNum)) {
            return true;
        }
        else { return false; }
    }

};

int main()
{
    Solution mySolution;
    std::cout << mySolution.romanToInt("VX") << std::endl;
}
