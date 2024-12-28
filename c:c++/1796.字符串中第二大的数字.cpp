/*
 * @lc app=leetcode.cn id=1796 lang=cpp
 *
 * [1796] 字符串中第二大的数字
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int secondHighest(string s) {
        int first=-1, second=-1;
        for(auto i:s){
            if(isdigit(i)){
                int num=i-'0';
                if(num>first){
                    second=first;
                    first=num;
                }else if(num<first&&num>second){
                    second=num;
                }
            }
        }
        return second;
    }
};
// @lc code=end

