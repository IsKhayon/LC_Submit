/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */

#include<vector>
using namespace std;
// @lc code=start
class MyCalendar {
private:
    vector<int> start, end;
public:
    /**
     * @brief 构造函数，初始化日程安排表
     * 
     * 初始化一个空的日程安排表，使用`vector`来存储已经预订的日程。
     * `vector`中的元素是`int`，分别表示一个日程的开始时间和结束时间。
     * 
     * @param None
     * @return None
     */
    MyCalendar() { 
    }
    
    /**
     * @brief 预订日程
     * 
     * 尝试预订一个新的日程，如果该日程与已有的日程不冲突，则预订成功，返回`true`；否则返回`false`。
     * 日程冲突的定义是：新日程的开始时间小于已有日程的结束时间，且新日程的结束时间大于已有日程的开始时间。
     * 
     * @param startTime 新日程的开始时间
     * @param endTime 新日程的结束时间
     * @return bool 如果预订成功返回`true`，否则返回`false`
     */
    bool book(int startTime, int endTime) {
        // 遍历已有的日程
        for (int i = 0; i < start.size(); i++) {
            // 如果新日程与已有日程冲突，返回false
            if (!(end[i] <= startTime || endTime <= start[i])) {
                return false;
            }
        }
        // 如果新日程与已有的日程不冲突，将新日程添加到日程安排表中
        start.push_back(startTime);
        end.push_back(endTime);
        // 返回true表示预订成功
        return true;
    }

};
