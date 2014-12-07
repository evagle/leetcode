@file string-to-integer-atoi/.md  
@author  Brian  
@version 1.0  
@date 2014-12-07  


##Two Sum [ [sourcecode](../src/StringToIntegerAtoi.cpp) | [problem](https://oj.leetcode.com/problems/string-to-integer-atoi/) ]

##分析
atoi的题目虽然在面试中已经面烂了，但是自己写这道题的时候还是提交了将近10次才过。问题的根源在于未在写代码之前分析清楚各种边界情况。   

###坑：
1. 首先，前导空格处理
2. 正负号处理，可以有正负号
3. 溢出处理 

其中前两个想到了就比较简单，关键第3个如何处理。在leetcode里的设定是溢出时返回最接近的值。   


