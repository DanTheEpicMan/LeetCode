//Given a sorted array of distinct integers and a target value, return the
//index if the target is found. If not, return the index where it would be if it were
//inserted in order.
//
// You must write an algorithm with O(log n) runtime complexity.
//
//
// Example 1:
//
//
//Input: nums = [1,3,5,6], target = 5
//Output: 2
//
//
// Example 2:
//
//
//Input: nums = [1,3,5,6], target = 2
//Output: 1
//
//
// Example 3:
//
//
//Input: nums = [1,3,5,6], target = 7
//Output: 4
//
//
//
// Constraints:
//
//
// 1 <= nums.length <= 10⁴
// -10⁴ <= nums[i] <= 10⁴
// nums contains distinct values sorted in ascending order.
// -10⁴ <= target <= 10⁴
//
//
// Related Topics Array Binary Search 👍 17332 👎 814

1 3 5

2 3 4 5
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;
        int mid = high/2;
        while(high - low > 2) {
            mid = (high+low)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        bool wasLess = true;
        int calced = nums.size()-1;
        if (calced - low > 2) {
            calced = low + 2;
        }
        for (int i = low; i <= calced; i++) {
            if (nums[i] >= target) {
                return i;
            }
        }
        if (target > nums[nums.size()-1]) {
            return nums.size();
        } else if (target < nums[0]) {
            return 0;
        }
        return high;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

Success:
    Runtime:0 ms, faster than 100.00% of C++ online submissions.
    Memory Usage:13.5 MB, less than 76.24% of C++ online submissions.