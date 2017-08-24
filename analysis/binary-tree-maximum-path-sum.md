## Binary Tree Maximum Path Sum [ [sourcecode](../src/BinaryTree MaximumPathSum.cpp) | [problem](https://leetcode.com/problems/binary-tree-maximum-path-sum/) ]


##分析
求二叉树中任意两个节点路径的和的最大值。
用递归法求解。有三种情况：
1. 最长路径在左子树中，answer[root] = answer[root->left]
2. 最长路径在右子树中，answer[root] = answer[root->right]
3. 最长路径包含root节点，用leftMax[root]表示以左子树某个节点开始到root结尾的路径的最大值，rightMax[root]表示以右子树某个节点开始到root结尾的路径的最大值
``
answer[root] = max(leftMax[root->left], 0) + root + max(rightMax[root->right],0)
leftMax[root] = max(
	max(leftMax[root->left], 0),
	max(rightMax[root->right],0)
	) + root
``


##解法

