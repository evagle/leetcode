## Count of Range Sum [ [sourcecode](../src/count-of-range-sum.cpp) | [problem](https://leetcode.com/problems/count-of-range-sum/) ]

##解法分析
###方法1：分治法

1. mid将数组分为，[left,mid],[mid+1,right]两部分
2. 分别求两个子数组符合条件的区间个数
3. O(n)时间内求包括mid和mid+1两个数的区间个数

	+ 用sum[i]先记录a[0]-a[i]的和，区间i，j的和等于sum[j]-sum[i]
	+ 将sum[left:mid]和sum[mid+1,right]分别递增排序，考虑merge sort，在求子数组[left,mid]的时候对sum[left:mid]排序，时间就是O(n)
	+ 遍历sum[left:mid]，用l表示，找到sum[mid+1,right]中符合条件的个数，用r1，r2表示区间，由于是排序好的，l1增加时，sum[l]也是增长的，所以r1，r2也是递增或者是不变的，否则就不满足条件sum[r]-sum[l]<lower_bound了。所以l和r只需要遍历一遍，时间复杂度O(n)
	+ mergesort将sum[left:right]排序

###方法二：二叉搜索树
依然用sum[i]先记录a[0]-a[i]的和，
以i为结尾的区间，j属于0-(i-1),如果能在O(logn)时间找出来j的上界下界，那总的时间复杂度就是O(nlogn),可以用二叉搜索树来存储sum数组
，查找和插入都是O(logn). 如果担心二叉搜索树退化，可以用平衡二叉搜索树。

1. 遍历数组a
2. 计算sum[i]
3. 在BST中查找sum[i]-upper_bound<sum[j]和sum[i]-lower_bound>sum[j]，从而计算满足条件的j的数量
4. 将sum[i]插入BST中

##步骤或伪代码
