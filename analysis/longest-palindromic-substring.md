
##Longest Palindromic Substring [ [sourcecode（中心扩展）](../src//LongestPalindromicSubstring.cpp) | [problem](https://oj.leetcode.com/problems//longest-palindromic-substring/) ]

##分析
找最长回文字串。

#### 最笨的方法，暴力枚举，复杂度O(n^3)
找出每一个子串，然后判定子串是否是回文，如果是回文则记录长度，然后将最长的输出。

```
for i < strlen	
   for j < strlen	
		判断substring(i, j-i)是否是回文
```
#### 中心扩展法 复杂度O(n^2)
所谓中心扩展，就是以字符串中每一个字符为中心，搜索以它为中心的字符串长度，并记录，之后输出最长的。		
这个方法有个地方需要注意的就是，奇数回文串和偶数回文串需要分开考虑。     	
例如abaabba, 其中，    
aba是奇数回文串，对于这种，直接以b为中心，然后分别往左和往右扩展，直到左右不相等即可。    
abba是偶数回文串，对于这种，以两个b为中心，然后向两边扩展，直到左右不相等。

#### DP算法 复杂度O(n^2)
P[i,j]=0表示子串[i,j]不是回文串。P[i,j]=1表示子串[i,j]是回文串。     

初始化：P[i,i]=1
dp方程：       

	P[i,j] = P[i+1,j-1], if(s[i]==s[j])
	P[i,j] = 0         , if(s[i]!=s[j])


#### Manacher算法 复杂度O(n)



		


