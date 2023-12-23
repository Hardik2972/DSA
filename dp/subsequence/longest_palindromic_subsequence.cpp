#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   int lcs(string s,string t){
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
        int n = s.size();
        int m = t.size();
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
};