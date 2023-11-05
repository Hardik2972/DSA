
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long recursion(int index,int check,vector<int>& prices,vector<vector<long>> &dp){
        if(index<0){
            if(check) return INT_MIN;
            return 0;
        }
        long profit = 0;
        if(dp[index][check]!=-1) return dp[index][check];
        if(check){
            profit =  max((-prices[index]+recursion(index-1,!check,prices,dp)),recursion(index-1,check,prices,dp));
        }
        else{
            profit =  max((prices[index]+recursion(index-1,!check,prices,dp)),recursion(index-1,check,prices,dp));
        }
        return dp[index][check]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n,vector<long>(2,-1));
        recursion(n-1,0,prices,dp);
        return dp[n-1][0];
    }
};