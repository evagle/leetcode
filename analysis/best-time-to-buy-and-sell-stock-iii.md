## Word Ladder [ [sourcecode](../src/WordLadder.cpp) | [problem](https://oj.leetcode.com/problems/word-ladder/) ]


dp解法：
设dp[k][i]表示到price[i]位置，k次transaction能带来的最大的profit
如果price[i]处没有交易：
    dp[k][i] = dp[k][i-1]
如果在price[i]卖出：
    dp[k][i] = max(price[i]-price[j]+dp[k-1][j-1]) (j为第k次交易买入，j=[0,i-1])
如果对于每个i都需要遍历一遍j，复杂度是O(n^2)
优化：max(price[i]-price[j]+dp[k-1][j-1])中，-price[j]+dp[k-1][j-1]每次都重复计算了，
当i=p时，j从1到p-1循环，i=p+1时，j从1到p循环,1到p-1和之前的是一样的，所以没有必要重复计算，
只需要计算j=p即，-price[p]+dp[k-1][p-1]的值
    
