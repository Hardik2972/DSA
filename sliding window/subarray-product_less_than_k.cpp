
#include<iostream>
#include<string>
#include<utility>
#include<vector>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int ans=0;
        long long product=1;
        while(r<nums.size()){
            product*=nums[r];
            while(product>=k && l<=r){
                product=product/nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;

        }
        return ans;
    }
};