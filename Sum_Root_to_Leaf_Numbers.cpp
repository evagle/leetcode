/**
 * @file Sum_Root_to_Leaf_Numbers.cpp
 * @Brief 
 * @author  Brian 
 * @version 1.0
 * @date 2013-09-08
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

#define fillzero(d) memset(d,0,sizeof(d))
#define print(arr,n) for(int i=0;i<n;i++) printf("%d ",arr[i]);printf("\n");
#define MAXINT 0x7fffffff
#define read(c) scanf("%d",&(c))
#define FOR(a,b) for(int i=(a);i<(b);i++)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 
class Solution {
    public:
        int sumNumbers(TreeNode *root) {
            if(root==NULL)
                return 0;
            int total = 0;
            dfs(root,0,total);
            return total;
        }   
        void dfs(TreeNode *root,int sum,int& total){
            if(root==NULL)
                return;
            if(root->left==NULL&&root->right==NULL){
                total += sum*10+root->val;
            }else{  
                dfs(root->left,sum*10+root->val,total);
                dfs(root->right,sum*10+root->val,total);
            }
        }   
};
int main(){

    return 0;
}
