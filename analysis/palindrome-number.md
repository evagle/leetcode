@file palindrome-number.md  
@author  Brian  
@version 1.0  
@date 2014-12-07  


##Two Sum [ [sourcecode](../src/Palindrome-Number.cpp) | [problem](https://oj.leetcode.com/problems/palindrome-number/) ]

##分析    

>1. 一个指针从最高位往最低位扫，另一个从最低位到最高位扫   
2. 如果相等，继续扫描，直到不相等，或者两个指针相遇   

###坑：
需要用long long算x得最高次方。比如，x = 123456789的时候，如果不用long long，就会产生溢出。溢出时变成负数，永远小于x，所以会发生死循环。           

    while (i <= x) { i *= 10;}
	

