## Maximum Gap [ [sourcecode](../src/maximum-gap.cpp) | [problem](https://leetcode.com/problems/maximum-gap/) ]

##解法分析
乱序排列的数组找出相邻两个数最大的差值。如果排序再找，就是O(nlogn)的时间。
O(n)的解法：桶排序。
先找出min和max，然后将max-min分成n-1等份，因为除去max和min，只有n-2个值，分成n-1等份，根据鸽巢原理，必然有一个是空的。那么gap>=(max-min)/n-1。而落在同一个桶内的所有元素的gap肯定小于桶宽度(max-min)/n-1。所以同一个桶内，只需要记录最小值和最大值，用来和相邻的桶比较。扫描一遍记录每个桶内元素的最小值最大值。然后再扫描一遍桶，相邻的有数的桶之间计算gap，取最大的gap就是结果。

##步骤或伪代码
