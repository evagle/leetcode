/**
 * @file Longest_Consecutive_Sequence.cpp
 * @Brief 
 * @author  Brian 
 * @version 1.0
 * @date 2013-09-09
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define fillzero(d) memset(d,0,sizeof(d))
#define print(arr,n) for(int i=0;i<n;i++) printf("%d ",arr[i]);printf("\n");
#define MAXINT 0x7fffffff
#define read(c) scanf("%d",&(c))
#define FOR(a,b) for(int i=(a);i<(b);i++)
/*
 * hash_*(ex: hash_map,hash_set...) are desperated.
 * Use unordered_*(unordered_map, unordered_set ) instead.
 */
class Solution {
    public:
        int longestConsecutive(vector<int> &num) {

            unordered_set<int>::const_iterator it;
            unordered_set<int> set;
            for(int i=0;i<num.size();i++){
                if(set.find(num[i])==set.end()){
                    set.insert(num[i]);
                }
            }
            int maxc = 0;
            for(int i=0;i<num.size();i++){
                int c = 1 ;
                if(set.find(num[i])!=set.end()){
                    int cur = num[i]+1;
                    while(set.find(cur)!=set.end()){
                        set.erase(cur);
                        c++;
                        cur++;

                    }
                    cur = num[i]-1;
                    while(set.find(cur)!=set.end()){
                        set.erase(cur);
                        c++;
                        cur--;
                    }
                    if(maxc<c)
                        maxc=c;

                }
            }

            return maxc;
        }
};
int main(){
    unordered_map<int,int> map;
    map[1]=1;
    unordered_set<int> map;
    map.
        cout<<map[i]<<endl;
    return 0;
}
