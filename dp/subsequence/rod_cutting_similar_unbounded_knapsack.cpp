
#include<iostream>
#include<vector>
using namespace std;
int recursion(int index,int w,vector<int> &profit,vector<int> &weight,vector<vector<int>> &dp){
    if(index==0){
        if(w==0) return dp[index][w]=0;
        if(w%weight[0]==0) return dp[index][w]=(w/weight[0])*profit[0];
        return dp[index][w]=0;

    }
    if(dp[index][w]!=-1) return dp[index][w];
    int notPickUp = recursion(index-1,w,profit,weight,dp);
    int pickUp = 0;
    if(weight[index]<=w){
        pickUp = profit[index] + recursion(index,w-weight[index],profit,weight,dp);
    }
    return dp[index][w]=max(notPickUp,pickUp);
}
int cutRod(vector<int> &price, int n)
{   
	vector<int> weight(n,-1);
	for(int i=0;i<n;i++) weight[i]=i+1;
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
    recursion(n-1,n,price,weight,dp);
    return dp[n-1][n];
}
