#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int recursion(int i,vector<int>& nums,vector<int> &dp){
        if(i==0 || i==1) return dp[i]=nums[i];
        if(dp[i]!=-1) return dp[i];
        int maxi = -1e9;
        for(int j=i-2;j>=0;j--){
            maxi=max(maxi,recursion(j,nums,dp));
            cout<<j<<endl;
        }
        return dp[i]=maxi+nums[i];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(),-1);
        recursion(nums.size()-1,nums,dp);
        recursion(nums.size()-2,nums,dp);
        return  max(dp[nums.size()-1],dp[nums.size()-2]);
        
    }
};