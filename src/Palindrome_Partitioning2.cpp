/**
 * @file Palindrome_Partitioning2.cpp
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
        int minCut(string s) {

            int len = s.length();
            int* cutNum =  new int[len];
            //int[i][j]: true if substr(i,j) is palindrome, false if not
            bool** palindrome = new bool*[len];
            for(int i=0;i<len;i++)
                palindrome[i] = new bool[len];
            //init palindrome
            
            for(int l=0;l<=len;l++){
                for(int i=0;i<=len-l&&i<len;i++){
                    if(l==1||l==0) palindrome[i][l] = true;
                    else{
                        palindrome[i][l] = palindrome[i+1][l-2]&&(s[i]==s[i+l-1]);
                    }
                }
            }
            for(int i=0;i<len;i++)
                cutNum[i]=MAXINT;
            cutNum[0]=0;
            for(int i=1;i<len;i++){
                for(int j=0;j<=i;j++){
                    string subs = s.substr(j,i-j+1);
                    if(palindrome[j][i-j+1]){
                        if(j==0){
                            cutNum[i]=0;
                        }else{
                            if(cutNum[i]>cutNum[j-1]+1)
                                cutNum[i] = cutNum[j-1]+1;
                        }
                    }

                }
            }
            return cutNum[len-1];
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
};
int main(){
    Solution s;
cout<< s.minCut("abv");
    //    cout<< s.minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")<<endl;
    return 0;
}
