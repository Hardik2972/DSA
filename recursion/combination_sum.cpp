#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void recursion(int index,vector<vector<int>> &ans,vector<int> candidates,int target,vector<int> input){
        if(target == 0) {
            ans.push_back(input);
            return;
        }
        if(index == candidates.size()){
            
            return;
        }
        if(candidates[index]<=target){
            input.push_back(candidates[index]);
            recursion(index,ans,candidates,target-candidates[index],input);
            input.pop_back();
            
        }
        recursion(index+1,ans,candidates,target,input);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> input;
        int index =0 ;
        recursion(index,ans,candidates,target,input);
        return ans;
    }
};