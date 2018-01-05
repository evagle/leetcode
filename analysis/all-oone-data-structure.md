## All O(1) Data Structrue [ [sourcecode](../src/all-oone-data-structure.cpp) | [problem](https://leetcode.com/problems/all-oone-data-structure/) ]

##解法分析
加一，减一，获得最大值最小值的操作复杂度都是O(1)

用一个hashmap存储key-value（map），value是双端队列的value对应的node,然后用一个双端队列存储value-keyslist.即存储某个值对应的所有keys(deque)。双端队列的头和尾分别是最小值和最大值。

+ 加一：deque[val].remove(key), deque[val+1].add(key)，如果deque中没有val+1则需要添加一个新的node。需要更新map[key]的node为deque[val+1]
+ 减一：deque[val].remove(key), deque[val-1].add(key)，如果val-1=0则不添加了。还需要更新map[key]的node为deque[val-1]
+ GetMaxKey：根据最大值maxVal，从deque尾部获得最大值然后pop出来一个key
+ GetMinKey：与GetMaxKey类似，只不过从deque头部取

LFUcache的题与此题基本完全一致，每次操作增加一次，cache用一个map来记录key-value键值对，然后双端队列存储访问次数为n的所有key的列表，

```
1 -> a,b 访问过1次的key有a,b
||
2 -> c   访问过2次的key有c
||
4 -> d   访问过4次的key有d
```

get(key) 

- Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1. 

put(key, value) 

- Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.


##步骤或伪代码
