class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def __init__(self):
        # Initialize the maximum sum for each instance
        self.maxSum = -float('inf')

    def maxPathSum(self, root):
        """
        Calculates the maximum path sum in a binary tree.
        
        :type root: TreeNode
        :rtype: int
        """
        self.postOrderTraversal(root)
        return self.maxSum

    def postOrderTraversal(self, root):
        """
        Post-order traversal of the tree to calculate the maximum path sum
        rooted at each node.
        
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        
        # Calculate max path sum for left and right subtrees
        l_val = max(self.postOrderTraversal(root.left), 0)
        r_val = max(self.postOrderTraversal(root.right), 0)

        # Calculate the maximum path sum with the current node as the highest node
        currentMax = l_val + r_val + root.val

        # Update the global maximum path sum if the current path sum is greater
        self.maxSum = max(self.maxSum, currentMax)

        # Return the maximum path sum rooted at this node, considering only one subtree path
        return max(l_val, r_val) + root.val
