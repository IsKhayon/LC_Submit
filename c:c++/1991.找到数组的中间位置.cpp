/*
 * @lc app=leetcode.cn id=1991 lang=cpp
 *
 * [1991] 找到数组的中间位置
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0;
        for (auto &i : nums){
            sum += i;
        }

        int left = 0;
        for (int MiddleIndex = 0; MiddleIndex < nums.size(); MiddleIndex++){    
            left += nums[MiddleIndex];
            if(left * 2 == sum + nums[MiddleIndex]) return MiddleIndex;            
        }
        return -1;

        // int s = reduce(nums.begin(), nums.end());
        // int left_s = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (left_s * 2 == s - nums[i]) {
        //         return i;
        //     }
        //     left_s += nums[i];
        // }
        // return -1;
    }
};
// @lc code=end

