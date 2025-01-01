/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /**
     * @brief 合并重叠的区间
     * 
     * @param intervals 输入的区间列表
     * @return vector<vector<int>> 合并后的区间列表
     */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 首先对区间列表进行排序，确保区间按照左端点升序排列
        sort(intervals.begin(), intervals.end());
        // 初始化变量 left 和 right，用于存储当前处理的区间的左右端点
        int left, right;
        // 创建一个空的向量 ans，用于存储合并后的区间
        vector<vector<int>> ans;
        // 遍历输入的区间列表 intervals
        for(int i = 0; i < intervals.size(); i++){
            // 将当前区间的左右端点分别赋值给 left 和 right
            left = intervals[i][0];
            right = intervals[i][1];
            
            // 如果 ans 为空，或者 ans 中最后一个区间的右端点小于当前区间的左端点（即不重叠）
            if(!ans.size() || ans.back()[1] < left){
                // 则将当前区间直接添加到 ans 中
                ans.push_back({left, right});
            }
            // 如果 ans 中最后一个区间的右端点大于等于当前区间的左端点，且最后一个区间的左端点小于等于当前区间的左端点
            else if(ans.back()[1] >= left && ans.back()[0] <= left){
                // 则更新 ans 中最后一个区间的右端点为当前区间的右端点和 ans 中最后一个区间的右端点中的较大值
                ans.back()[1] = max(ans.back()[1], right);
            }
            // 如果 ans 中最后一个区间的右端点大于等于当前区间的右端点，且最后一个区间的左端点小于等于当前区间的左端点
            else if(ans.back()[1] >= right && ans.back()[0] <= left){
                // 则跳过当前区间，因为它已经被包含在 ans 中最后一个区间内
                continue;
            }
            // 如果 ans 中最后一个区间的右端点大于等于当前区间的右端点，且最后一个区间的左端点大于等于当前区间的左端点
            else if(ans.back()[1] >= right && ans.back()[0] >= left){
                // 则更新 ans 中最后一个区间的左端点为当前区间的左端点和 ans 中最后一个区间的左端点中的较小值
                // 更新 ans 中最后一个区间的右端点为当前区间的右端点和 ans 中最后一个区间的右端点中的较大值
                ans.back()[0] = min(ans.back()[0], left);
                ans.back()[1] = max(ans.back()[1], right);
            }
            // 如果 ans 中最后一个区间的右端点小于等于当前区间的右端点，且最后一个区间的左端点大于等于当前区间的左端点
            else if(ans.back()[1] <= right && ans.back()[0] >= left){
                // 则更新 ans 中最后一个区间的左端点为当前区间的左端点和 ans 中最后一个区间的左端点中的较小值
                // 更新 ans 中最后一个区间的右端点为当前区间的右端点和 ans 中最后一个区间的右端点中的较大值
                ans.back()[0] = min(ans.back()[0], left);
                ans.back()[1] = max(ans.back()[1], right);
            }
            // 如果以上条件都不满足，则将当前区间直接添加到 ans 中
            else{
                ans.push_back({left, right});            
            }
        }
        // 返回合并后的区间列表 ans
        return ans;
    }
};
// @lc code=end

