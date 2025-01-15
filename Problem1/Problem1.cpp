//Not part of leetcode, just to make it run
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for (int i = 0; i < nums.size(); i++) { //goes though every number 
            for (int j = 0; j < nums.size(); j++) { //goes through every number per number
                if (nums[i] + nums[j] == target && i != j) {
                    std::vector<int> myVec = { i, j };
                    return myVec;
                }
            }
        }
        return nums;
    }
};



//bad code but just for getting leetcode outputs
int main()
{
    Solution myObject;
    std::vector<int> example1{ 2,7,11,15 };
    std::vector<int> example2{ 3,2,4 };
    std::vector<int> example3{ 3,3 };
    std::vector<int> response1 = myObject.twoSum(example1, 9);
    std::vector<int> response2 = myObject.twoSum(example2, 6);
    std::vector<int> response3 = myObject.twoSum(example3, 6);
    std::cout << response1[0] << " " << response1[1] << std::endl;
    std::cout << response2[0] << " " << response2[1] << std::endl;
    std::cout << response3[0] << " " << response3[1] << std::endl;



}