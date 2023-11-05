
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    int recursion(int index,int W,int val[],int wt[],vector<vector<int>> &dp){
        if(index==0){
            if(wt[index]<=W){
                return dp[index][W]=val[index];
            }
            return dp[index][W]=0;
        }
        if(dp[index][W]!=-1) return dp[index][W];
        int notPickUp = recursion(index-1,W,val,wt,dp);
        int pickUp = 0;
        if(W>=wt[index])
           pickUp = val[index]+recursion(index-1,W-wt[index],val,wt,dp);
        return dp[index][W]=max(pickUp,notPickUp);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       recursion(n-1,W,val,wt,dp);
       return dp[n-1][W];
    }
};