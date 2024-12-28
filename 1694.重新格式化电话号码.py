#
# @lc app=leetcode.cn id=1694 lang=python3
#
# [1694] 重新格式化电话号码
#

# @lc code=start
from curses.ascii import isdigit


class Solution:
    def reformatNumber(self, number: str) -> str:
        # digits = list()  # 找出所有数字记录在字符串digits
        # for ch in number:
        #     if ch.isdigit():
        #         digits.append(ch)
        # size, pt = len(digits), 0  # size表示当前剩余字符串长度，pt为遍历使用的标记指针
        # ans = list()

        # # 当 size>4 时，取3个
        # # 当 size<=4 时，分情况讨论
        # while size > 0:
        #     if size > 4:
        #         ans.append("".join(digits[pt:pt+3]))
        #         pt += 3
        #         size -= 3
        #     else:
        #         if size == 4:
        #             ans.append("".join(digits[pt:pt+2]))
        #             ans.append("".join(digits[pt+2:pt+4]))
        #         else:
        #             ans.append("".join(digits[pt:pt+size]))
        #             break
        # return "-".join(ans)
        digits = list()
        for ch in number:
            if ch.isdigit():
                digits.append(ch)
        
        n, pt = len(digits), 0
        ans = list()

        while n > 0:
            if n > 4:
                ans.append("".join(digits[pt:pt+3]))
                pt += 3
                n -= 3
            else:
                if n == 4:
                    ans.append("".join(digits[pt:pt+2]))
                    ans.append("".join(digits[pt+2:pt+4]))
                else:
                    ans.append("".join(digits[pt:pt+n]))
                break
        
        return "-".join(ans)
# @lc code=end
