/**
 * @file Palindrome_Partitioning.cpp
 * @Brief 
 * @author  Brian 
 * @version 1.0
 * @date 2013-09-06
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

#define fillzero(d) memset(d,0,sizeof(d))
#define print(arr,n) for(int i=0;i<n;i++) printf("%d ",arr[i]);printf("\n");
#define MAXINT 0x7fffffff
#define read(c) scanf("%d",&(c))
#define FOR(a,b) for(int i=(a);i<(b);i++)
class Solution {
    public:
        struct Node{
            vector< vector<string> > vstr ;
        };
        vector<vector<string> > partition(string s) {

            int len = s.length();
            Node* nodes  = new Node[len];

            vector<string> str0;
            str0.push_back(s.substr(0,1));
            nodes[0].vstr.push_back(str0);

            for(int i=1;i<len;i++){
                for(int j=0;j<=i;j++){
                    string subs = s.substr(j,i-j+1);
                    if(is_palindrome(subs)){
                        if(j==0){
                            vector<string> tmp;
                            tmp.push_back(subs);
                            nodes[i].vstr.push_back(tmp);
                        }else{
                            for(int k=0;k<nodes[j-1].vstr.size();k++){
                                vector<string> tmp;
                                vector<string> pre = nodes[j-1].vstr[k];
                                for(int p=0;p<pre.size();p++){
                                    tmp.push_back(pre[p]);
                                }
                                tmp.push_back(s.substr(j,i-j+1));
                                nodes[i].vstr.push_back(tmp);  
                            }
                        }
                    }

                }
            }
            return nodes[len-1].vstr;
        }
        bool is_palindrome(string s){
            if(s.length() <= 1)
                return true;
            else{
                for(int i=0;i<s.length()/2;i++){
                    if(s[i]!=s[s.length()-i-1]){
                        return false;
                    }
                }    
            }
            return true;

        }
        void printv (vector<vector<string> > str){
            for(int i=0;i<str.size();i++){
                for(int j=0;j<str[i].size(); j++){
                    cout<<str[i][j]<<"\t";
                }
                cout<<endl;
            }
        }
};
int main(){
    Solution s;
    s.printv(s.partition("a"));
    return 0;
}
