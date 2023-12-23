#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<unordered_map>
using namespace std;
// #include<queue>
// *******************************************************question*****************************************
// 2963. Count the Number of Good Partitions
// You are given a 0-indexed array nums consisting of positive integers.
// A partition of an array into one or more contiguous subarrays is called good 
// if no two subarrays contain the same number.
// Return the total number of good partitions of nums.
// Since the answer may be large, return it modulo 109 + 7.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: 8
// Explanation: The 8 possible good partitions are: ([1], [2], [3], [4]), ([1], [2], [3,4])
// , ([1], [2,3], [4]), ([1], [2,3,4]), ([1,2], [3], [4]), ([1,2], [3,4]), ([1,2,3], [4]), and ([1,2,3,4]).
// **********************************************************solution*************************************************

#define mod (int)(1e9+7)
class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        // main two pointer approch to count no. sub groubs which have do not have any same no..
        // take example [d c c a b a b g g]
        // take i and j at d and dry run 
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        int i=0,j=0;
        int count = 0 ;
        while(i<nums.size()){
            if(i>j) count++;
            j=max(j,m[nums[i]]);
            i++;
        }
        count++;
        // ans = 2**(count-1)
        int ans = 1;
        for(int i=0;i<count-1;i++){
            ans=(ans*2)%mod;
        } 
        return ans;
    }

};