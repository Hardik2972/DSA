
#include<iostream>
#include<vector>
using namespace std;

// *************************************************question*****************************************
// 300. Longest Increasing Subsequence
// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// ********************************************code************************************************

class Solution {
public:
    int recursion(vector<int>& nums,int i,int prev,vector<vector<int>>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int notPickUp = recursion(nums,i+1,prev,dp);
        int pickUp = 0;
        if(nums[prev]<nums[i]){
            pickUp = 1 + recursion(nums,i+1,i,dp);
        }
        return dp[i][prev]=max(pickUp,notPickUp);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> nums1;
        nums1.push_back(INT_MIN);
        for(int i=0;i<nums.size();i++){
            nums1.push_back(nums[i]);
        }
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums1.size(),-1));
        return recursion(nums1,1,0,dp);
    }
};