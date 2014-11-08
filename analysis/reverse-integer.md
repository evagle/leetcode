
##Reverse Integer [ [sourcecode](../src/ReverseInteger.cpp) | [problem](https://oj.leetcode.com/problems/reverse-integer/) ]

##分析
将一个数字翻转获得新数字。

#### 解法
解法很简单，取模除10，直到为0。
 
##注意：
1. 100，2000这样的翻过了是1，2
2. 超过int存储值的例如10 0000 0003,反过来30 0000 0001，超过了int可表示范围，溢出然后变成了1
3. 负数情况，按照正数处理，然后在加上符号
		


