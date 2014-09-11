/**
 * @file two-sum.md
 * @Brief 
 * @author  Brian 
 * @version 1.0
 * @date 2014-09-11
 */


##Two Sum [ [sourcecode](../src/TwoSum.cpp) | [problem](https://oj.leetcode.com/problems/two-sum/) ]

##分析
这个题目看上去很简单，就是在一堆数里面找两个数，使得他们的和为给定的值。但是，其实这个题目要求比较高，而且坑很多。首先如果想要AC，普通的暴力枚举是不行的，因为时间复杂度是O(n^2)。
那还有两种方法：
1. 先排序，O(nlgn),然后遍历每个元素v，计算target-v，然后二分搜索target-v，不过因为需要输出序号，所以要注意的时排序的时候需要存储序号一起排序。
2. hash表。建立hash表，记录每个值的下表位置。例如，1，2，3，1，那hash表结构如下{1:[1,4],2:2,3:3}.然后遍历每个元素v，hash表里找target-v对应的下标，如果有和v不是相同下标的，那就是答案了。

###坑：
我一开始用得就是hash表，但是没有考虑到下面两种情况：
1. array=[3,2,4], target=6
2. array=[0,2,3,0], target=0
我的hash表存储的值是一个下标值，不是下标数组，没考虑相同元素出现的情况，所以对于第二种，0的下标本来有1，4，但是1被4覆盖了，导致找不到结果。然后如第一种情况，第一个元素是3，6-3也等于3，发现3在hashmap里有，下标是1，然后就输出1，1了，这是没有判断target-v不能和v是同一个位置导致的。所以找target-v时，需要排除v自己的下标，不然就相当于一个元素用了两次。

