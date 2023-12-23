#include<iostream>
#include<unordered_map>
using namespace std;
// *******************************question*************************
// 2962. Count Subarrays Where Max Element Appears at Least K Times

// You are given an integer array nums and a positive integer k.

// Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

// A subarray is a contiguous sequence of elements within an array.

// ********************example************************************
// Input: nums = [1,3,2,3,3], k = 2
// Output: 6
// Explanation: The subarrays that contain the element 3 at least 2 times are: 
// [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
// ********************code****************************************

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int l=0;
        int r=0;
        int count=0;
        long long ans=0;
        while(r<nums.size()){
            if(nums[r]==maxi) count++;
            
                
                while(count>=k){
                    ans+=nums.size()-r; // The main crux of this algorithm remeber
                    if(nums[l]==maxi) count--;
                    l++;
                }
            
            r++;
        }
        return ans;
    }
};