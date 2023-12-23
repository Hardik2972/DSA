
#include<iostream>
#include<vector>
using namespace std;

// ********************************************question**********************************************
// 96. Unique Binary Search Trees
// Given an integer n, return the number of structurally unique BST's (binary search trees) 
// which has exactly n nodes of unique values from 1 to n.
// Example 1:
// Input: n = 3
// Output: 5
// ************************************************solution********************************************


// *************memoization***********************
vector<int> dp(20,-1);
class Solution {
public:
    int numTrees(int n) {
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans =0;
        for(int i=1;i<=n;i++){
            ans+=(numTrees(i-1)*numTrees(n-i));
        }
        return dp[n]=ans;
    }
};

// ********************************tabulation*******

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=(dp[j-1]*dp[i-j]);
            }
        }
        return dp[n];
    }
};