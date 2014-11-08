
##ZigZag Conversion [ [sourcecode](../src/ZigZagConversion.cpp) | [problem](https://oj.leetcode.com/problems/zigzagconversion/) ]

##分析
将字符串按照zigzag形式输出。纯模拟。找规律。

#### 模拟
第一行和最后一行：s[i+2*(nRows - 1) * k],k=0,2,3,,,,
中间的行：s[i+2*(nRows - 1) * k],k=0,2,3,,,,
	s[-i+2*(nRows - 1) * k],k=1,2,3,,,,

 
##注意：
这题着实有些坑，算法很简单，直接模拟就行，根据规律一行一行的扫描输出，关键是TLE和MLE让人蛋疼。

1. 不能使用char数组然后再转化成string，会导致TLE
2. 不能直接新建string然后不断append，会导致Memory Limit Exceeded，估计是string扩展的方式是翻倍的，反正初始化结果string的时候，调用resize预先分配好空间即可。
3. 考虑nRows为1的情况，直接返回s
		


