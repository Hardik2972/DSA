
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int recursion(int index,int amount,vector<int> & coins,vector<vector<int>> &dp){
        if(index==0){
            if(amount==0){
                return dp[index][amount]=0;
            }

            if(amount%coins[index]==0) return dp[index][amount]=amount/coins[index];
            return dp[index][amount]=1e9;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int notPickUp = recursion (index-1,amount,coins,dp);
        int pickUp = 1e9;
        if(coins[index]<=amount){
            pickUp=1+recursion(index,amount-coins[index],coins,dp);
        }
        return dp[index][amount]=min(notPickUp,pickUp);

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));

    
        recursion(coins.size()-1,amount,coins,dp);
        int result = dp[coins.size()-1][amount];
        if(result == 1e9) return -1;
        return result;
    }
};