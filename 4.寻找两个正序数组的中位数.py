#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个正序数组的中位数
#

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)  # 数组1的长度
        n = len(nums2)  # 数组2的长度
        left = (m + n + 1) // 2  # 左中位数的位置
        right = (m + n + 2) // 2  # 右中位数的位置
        return (self.findKthSmallest(nums1, nums2, left) + self.findKthSmallest(nums1, nums2, right)) / 2
    

    def findKthSmallest(self, nums1: List[int], nums2: List[int], k: int) -> int:
        if not nums1:
            return nums2[k - 1]
        if not nums2:
            return nums1[k - 1]
        if k == 1:
            return min(nums1[0], nums2[0])
        
        i = min(k // 2, len(nums1))
        j = min(k // 2, len(nums2))

        if nums1[i-1] < nums2[j-1]:
            return self.findKthSmallest(nums1[i:], nums2, k-i)
        else:
            return self.findKthSmallest(nums1, nums2[j:], k-j)
# @lc code=end

