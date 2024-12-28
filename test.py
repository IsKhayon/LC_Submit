# 字符串 ababc
#  abba
#  abaab
# 找到最长公共前缀


# from ast import List
from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        def isCommonPrefix(length):
            str0, count = strs[0][:length], len(strs)
            return all(strs[i][:length] == str0 for i in range(1, count))

        if not strs:
            return ""

        minLength = min(len(s) for s in strs)
        low, high = 0, minLength
        while low < high:
            mid = (high - low + 1) // 2 + low
            if isCommonPrefix(mid):
                low = mid
            else:
                high = mid - 1

        return strs[0][:low]
    
list1 = ['ababc', 'abba', 'abaab']
p = Solution().longestCommonPrefix(list1)
print(p)