#
# @lc app=leetcode.cn id=1367 lang=python3
#
# [1367] 二叉树中的链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, head: ListNode, root: TreeNode) -> bool:
        """
        深度优先搜索函数，用于检查从当前二叉树节点开始是否存在与链表匹配的路径。

        :param head: 链表的当前节点
        :param root: 二叉树的当前节点
        :return: 如果存在匹配路径则返回True，否则返回False
        """
        # 如果链表已经遍历完，说明找到了匹配的路径
        if not head: return True
        # 如果二叉树已经遍历完，说明没有找到匹配的路径
        if not root: return False
        # 如果当前二叉树节点的值与链表节点的值不相等，说明不是匹配的路径
        if head.val != root.val: return False
        # 递归地检查左子树或右子树是否存在匹配的路径
        return self.dfs(head.next, root.left) or self.dfs(head.next, root.right)

    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        """
        检查二叉树中是否存在一条从根节点到叶子节点的路径，该路径上的节点值组成的序列与给定的链表相同。

        :param head: 链表的头节点
        :param root: 二叉树的根节点
        :return: 如果存在这样的路径则返回True，否则返回False
        """
        # 如果二叉树为空，说明不存在匹配的路径
        if not root: return False
        # 如果从当前二叉树节点开始存在匹配的路径，直接返回True
        if self.dfs(head, root): return True
        # 递归地检查左子树或右子树是否存在匹配的路径
        return self.isSubPath(head, root.left) or self.isSubPath(head, root.right)

# @lc code=end

