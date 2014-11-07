
##Longest Substring Without Repeating Characters  [ [sourcecode](../src/LongestSubstringWithoutRepeatingCharacters.cpp) | [problem](https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/) ]

##分析
找字符串的不包含相同字符的最长字串。

#### 简单动态规划
len[i]表示以s[i]结尾的不包含相同字符的最长字串长度。	
len[i]计算方法：
	
	* 如果s[i-1]结尾的最长字串中包含s[i],那么len[i]=i- last_position[s[i]]		
	* 否则就是s[i-1]结尾的字符串长度加1， len[i] = len[i-1] + 1
 
##注意：
这题没什么坑，就是注意一下初始化条件。last_position初始化为-1, len数组初始化为0
		


