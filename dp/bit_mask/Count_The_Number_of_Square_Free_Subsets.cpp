****************************************Question
#include<iostream>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    vector<int> prime={2,3,5,7,11,13,17,19,23,29};
    int recursion(int i,int mask,vector<int>& nums,vector<vector<int>>& dp){
        if(i==nums.size()) return 1;
        if(dp[i][mask]!=INT_MAX) return dp[i][mask];
        int notTakeIt = recursion(i+1,mask,nums,dp)%(int)(1e9+7);
        int takeIt = 0;
        int temp = mask;
        for(int j=0;j<10;j++){
            int count = 0;
            int num = nums[i];
            if(num%prime[j]==0){
                while(num%prime[j]==0){
                    count++;
                    num/=prime[j];
                }
                if(count>1 || (temp & (1<<j))) return dp[i][mask]=notTakeIt;
                else{
                    temp = temp | (1<<j);
                }
            }
        }
        takeIt = recursion(i+1,temp,nums,dp)%(int)(1e9+7);
        return dp[i][mask] = (takeIt + notTakeIt)%(int)(1e9+7);
    }
    int squareFreeSubsets(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(1024,INT_MAX));
        return (recursion(0,0,nums,dp)-1 + (int)(1e9+7))%(int)(1e9+7);
    }
};