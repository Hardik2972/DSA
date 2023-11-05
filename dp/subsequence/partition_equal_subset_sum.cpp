#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool recursion(vector<int> &nums,int target,int index,vector<vector<int>> &dp){
        if(index<0) return false;
        if(target==0) return dp[index][target]=true;
        if(target<0) return false;
        if(dp[index][target]!=-1) return dp[index][target];
        bool notPickUp=recursion(nums,target,index-1,dp);
        bool pickUp=recursion(nums,target-nums[index],index-1,dp);
        return dp[index][target]=(notPickUp||pickUp);
    }
    bool canPartition(vector<int>& nums) {
        int target = 0;
        
        for(int i=0;i<nums.size();i++) target+=nums[i];
        if(target%2) return false;
        target/=2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        recursion(nums,target,nums.size()-1,dp);
        return dp[nums.size()-1][target];
    }
};