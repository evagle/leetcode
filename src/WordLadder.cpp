/**
 * @file Word_Ladder.cpp
 * @Brief 
 * @author  Brian 
 * @version 1.0
 * @date 2013-09-10
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

#define fillzero(d) memset(d,0,sizeof(d))
#define print(arr,n) for(int i=0;i<n;i++) printf("%d ",arr[i]);printf("\n");
#define MAXINT 0x7fffffff
#define read(c) scanf("%d",&(c))
#define FOR(a,b) for(int i=(a);i<(b);i++)
class Solution {
    public:
        int dfs(string start,string end, unordered_set<string> &dict, vector<string> path, int step,unordered_set<string> &path_set){
            string last = path[step];
            if(end.compare(last)==0){
                for(int i=0;i<step;i++)
                    cout<<path[i]<<"\t";
                cout<<endl;
                return step;
            }
            int mins = 0x7fffffff;
            for(int i=0;i<last.length();i++){
                string tmp;
                tmp.assign(last);
                for(int c='a';c<='z';c++){
                    if(c!=last[i]){
                        tmp[i]=c;
                        if(path_set.find(tmp)==path_set.end()&&
                            dict.find(tmp)!=dict.end()){
                            path.push_back(tmp);
                            path_set.insert(tmp);
                            int count = dfs(start,end,dict,path,step+1,path_set);
                            if(count >0 && count < mins)
                                mins = count;
                            path.pop_back();
                            path_set.erase(tmp);
                        }
                    }
                }
            }
            if(mins==0x7fffffff)
                return -1;
            return mins;
        }
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            dict.insert(end);
            vector<string> path;
            path.push_back(start);
            unordered_set<string> path_set;
            path_set.insert(start);
            return dfs(start,end,dict,path,0,path_set)+1;
        }
};
int main(){
    unordered_set<string> dict;
    //"hot","dot","dog","lot","log"
//dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    Solution s;
    cout<<s.ladderLength("hit","cog",dict);
    return 0;
}
