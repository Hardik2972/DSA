#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 0;
        int f = 0;
        // for cycle detection
        while(true){
            s=nums[s];
            f=nums[nums[f]];
            if(s==f) break;
        }
        // for finding the cycle starting point
        int p = 0;
        while(true){
            p=nums[p];
            s=nums[s];
            if(s==p) return p;
        }
    }
};