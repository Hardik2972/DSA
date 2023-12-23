
#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    bool isAllStars(string s,int i){
        for(int ii = 1;ii<=i;ii++){
            if(s[ii-1]!='*') return false;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        string t = s;
        s = p;
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 && j==0) dp[i][j]=true;
                else if(i==0 && j>0) dp[i][j]=false;
                else if(j==0 && i>0){
                    dp[i][j] = isAllStars(s,i);
                }
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==t[j-1] || s[i-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(s[i-1]!='*') dp[i][j]=false;
                else{
                    dp[i][j]=(dp[i-1][j]||dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};