#define MOD 1000000007

#include<iostream>
#include<vector>
using namespace std;

int findWays(vector<int>& arr, int k)
{ 
	int target=k;
	vector<vector<int>> dp(arr.size(),vector<int>(k+1,0));
	for(int i=0;i<arr.size();i++) dp[i][0]=1;
	if(arr[0]<=target) dp[0][arr[0]]=1;
	for(int i=1;i<arr.size();i++){
          for (int j = 1; j <= target; j++) {
            int notPickUp = dp[i - 1][j];
            int pickUp = 0;
            if (arr[i] <= j)
              pickUp = dp[i - 1][j - arr[i]];
            dp[i][j] = (pickUp + notPickUp) % MOD;
          }
    }
    return dp[arr.size() - 1][target];
}