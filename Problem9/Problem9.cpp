#include <iostream>
#include <string>

//leetcode class
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

//execution 
int main()
{
    Solution mySolution;
    std::cout << mySolution.isPalindrome(31213) << std::endl;
}

