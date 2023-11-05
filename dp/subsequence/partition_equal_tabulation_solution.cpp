#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(int i=0;i<nums.size();i++) target+=nums[i];
       
        if(target%2) return false;
        target/=2;
        vector<vector<int>> grid(nums.size(),vector<int>(target+1,0));
        for(int i=0;i<nums.size();i++) grid[i][0]=1;
        if(nums[0]<=target) grid[0][nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<target+1;j++){
                int notpickup = grid[i-1][j];
                int pickup = 0;
                if(j>=nums[i]){
                    pickup = grid[i-1][j-nums[i]];
                }
                if (pickup||notpickup) grid[i][j]=1;
            }
        }
        return grid[nums.size()-1][target];
    }
};