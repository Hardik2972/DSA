#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int matching(int i,int j,string s,string t,vector<vector<int>> &dp){
        if(i<0) return dp[i+1][j+1]=j+1;
        if(j<0) return dp[i+1][j+1]=i+1;
        if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];
        if(s[i]==t[j]){
            return dp[i+1][j+1]=matching(i-1,j-1,s,t,dp);
        }
        else{
            int replace = 1 + matching(i-1,j-1,s,t,dp);
            int delet = 1 + matching(i-1,j,s,t,dp);
            int insert = 1 + matching(i,j-1,s,t,dp);
            return dp[i+1][j+1]=min(replace,min(delet,insert));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        matching(n-1,m-1,word1,word2,dp);
        return dp[n][m];
    }
};