#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int mod = 1003;
class Solution{
public:
    int recursion(int i,int j,int isTrue,string s,auto& dp){
        if(i>j) return 0;
        if(i==j){
            if(isTrue){
                return s[i]=='T';
            }
            else return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        int ans = 0;
        for(int k=i+1;k<=j-1;k+=2){
            int lt = recursion(i,k-1,1,s,dp);
            int lf = recursion(i,k-1,0,s,dp);
            int rt = recursion(k+1,j,1,s,dp);
            int rf = recursion(k+1,j,0,s,dp);
            if(s[k]=='&'){
                if(isTrue){
                    ans=(ans+(lt*rt)%mod)%mod;
                }
                else{
                    ans=(ans+(lt*rf)%mod)%mod;
                    ans=(ans+(lf*rt)%mod)%mod;
                    ans=(ans+(lf*rf)%mod)%mod;
                }
            }
            else if(s[k]=='|'){
                if(isTrue){
                    ans=(ans+(lt*rt)%mod)%mod;
                    ans=(ans+(lt*rf)%mod)%mod;
                    ans=(ans+(lf*rt)%mod)%mod;
                }
                else{
                    ans=(ans+(lf*rf)%mod)%mod;
                }
            }
            else{
                if(isTrue){
                    ans=(ans+(lf*rt)%mod)%mod;
                    ans=(ans+(lt*rf)%mod)%mod;
                }
                else{
                    ans=(ans+(lt*rt)%mod)%mod;
                    ans=(ans+(lf*rf)%mod)%mod;
                }
            }
        }
        return dp[i][j][isTrue]=ans;
    }
    int countWays(int n, string s){
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return recursion(0,n-1,1,s,dp);
    }
};