
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []

        l = []
        ans = []
        l_temp = []

        l.append(root)
        no_child = 1
        count = 0

        temp = TreeNode()
        while (len(l)):
            temp = l.pop(0)
            l_temp.append(temp.val)

            if temp.left is not None:
                l.append(temp.left)
                count += 1
            if temp.right is not None:
                l.append(temp.right)
                count += 1
            no_child -= 1
            if (not no_child):
                ans.append(l_temp)
                l_temp = []
                no_child = count
                count = 0

        return ans
