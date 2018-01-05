## Dungeon Game [ [sourcecode](../src/dungeon-game.cpp) | [problem](https://leetcode.com/problems/dungeon-game/) ]

##解法分析
knight从左上角开始，每次向左或者向下走一次，走到右下角需要多少生命力。生命力为0时死亡。

解法1：假设knignt以0生命力一直走，health[i][j]表示knight走到map[i][j]之后可能保留的生命值的最大值，如果是负数-a就表示kngiht至少要a+1的生命值才能活着走到map[i][j]。

	health[i][j]=max(health[i-1][j], health[i][j-1])+map[i][j].

然后只需要遍历一遍health[i][j]找出最小值，时间空间，空间复杂度都是O(mn)。

优化空间复杂度:health[i][j]只与health[i-1][j], health[i][j-1]相关。从左上角开始一行一行扫描更新health，扫描到map[i][j]时，更新health[i][j+1],health[i+1][j], 更新之后health[i][j+1]的值就是最大生命值。简化成一维数组记录。
health[j] = max(health[j-1],health[j])


解法2：从右下角倒推。

##步骤或伪代码
```
	health[0] = map[0][0];
	for (i,j) in map:
   		health[j] = max(health[j-1], health[j]) + map[i][j]
   	return health[m]
```