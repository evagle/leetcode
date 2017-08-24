## Word Ladder II [ [sourcecode](../src/WordLadderII.cpp) | [problem](https://leetcode.com/problems/word-ladder-ii/) ]


##分析
单词变换每次只能变一个字母，词典里是中间可以用来过度的词。题目可以转换为无向图最短路劲问题。
一个词是地图中的一个点，两个词如果只相差一个字母，就连一条边。给定起点和终点，求起点到终点的最短路径。用Dijkstra算法或者Bellman-Ford算法都行。

##解法

