
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
// *****************************************question**************************
// Given an integer array nums and an integer k, return the maximum sum of a non-empty
// subsequence of that array such that for every two consecutive integers in the subsequence,
// nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

// Input: nums = [10,2,-10,5,20], k = 2
// Output: 37
// Explanation: The subsequence is [10, 2, 5, 20].
// *********************************************solution***************************
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp = nums;
        priority_queue<pair<int,int>> q;
        q.push({nums[0],0});
        int ans = nums[0];
        for(int i=1;i<n;i++){
            while(!q.empty() && i-q.top().second>k){
                q.pop();
            }
            dp[i]=max(dp[i],dp[i]+q.top().first);
            q.push({dp[i],i});
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};