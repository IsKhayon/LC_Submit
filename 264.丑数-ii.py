#
# @lc app=leetcode.cn id=264 lang=python3
#
# [264] 丑数 II
#

# @lc code=start
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        nums = [2, 3, 5]
        q, vis = [], set()
        q.append(1)
        vis.add(1)
        while q:
            t = heapq.heappop(q)
            n -= 1
            if n == 0:
                return t
            for x in nums:
                if t * x not in vis:
                    heapq.heappush(q, t * x)
                    vis.add(t * x)
        return -1
# @lc code=end
