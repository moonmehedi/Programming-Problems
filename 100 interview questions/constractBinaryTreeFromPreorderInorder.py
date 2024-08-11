class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    global i

    def rec(self, pre, mp, min, mx):
        global i
        it=i
        if (mx < min):
            i-=1
            return None
        if i == len(pre):
            return None
        root = TreeNode(pre[i])
        if (mx == min):
            return root
        i += 1; 
        root.left = self.rec(pre, mp,  min, mp[pre[it]]-1)
        i += 1
        root.right = self.rec(pre, mp,  mp[pre[it]]+1, mx)

        return root

    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        global i
        mp = {}
        for a, ele in enumerate(inorder):
            mp[ele] = a
        i=0
        return self.rec(preorder, mp,  0, len(preorder)-1)


s = Solution()
s.buildTree([100,80,40,50,85,90,95,150,125,110,130,160,155,170],
[40,50,80,90,85,95,100,110,125,130,150,155,160,170])
