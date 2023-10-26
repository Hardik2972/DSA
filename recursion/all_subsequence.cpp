#include<iostream>
#include<vector>
using namespace std;




// BIT MANIPULATION METHOD
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=0;i<(1<<nums.size());i++){
            vector<int> temp;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);

        }
        return ans;
    }
};






// SIMPLE RECURSIVE METHOD
class Solution1 {
public:
    void recursion(vector<int> input,vector<int> output,int pointer,vector<vector<int>> &ans){
        if(pointer>=output.size()){
            ans.push_back(input);
            return ;
        }
        input.push_back(output[pointer]);
        recursion(input,output,pointer+1,ans);
        input.pop_back();
        recursion(input,output,pointer+1,ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> input;
        vector<int> output;

        vector<vector<int>> ans; 
        recursion(input,nums,0,ans);
        return ans;
    }
};