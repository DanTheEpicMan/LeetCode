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
        std::vector<std::string> romanNums{ "I", "V", "X", "L", "C", "D", "M" };
        std::vector<int> correspondingNums = { 1, 5, 10, 50, 100, 500, 1000 };

        int number = 0;
           
        //Roman numeral rules:
        // If the number after is bigger, than the list is that number - current number
        //If second number is smaller, is added to current number

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; i < romanNums.size(); j++) {
                if (s[i] == romanNums[j][0]) {
                    if (s[i + 1] == romanNums[j + 1][0]) { //if following number is bigger
                        number = number + correspondingNums[i + 1] - correspondingNums[i];
                    }
                    else { //if following number is not bigger
                        number = number + correspondingNums[i];
                    }
                }
            }
        }
        return number;
    }
};

int main()
{
    Solution mySolution;
    std::cout << mySolution.romanToInt("V") << std::endl;
}
