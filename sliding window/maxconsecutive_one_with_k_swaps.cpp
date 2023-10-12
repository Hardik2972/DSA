#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int len=0;
        int c=0;
        vector<int> v;
        if(k==0){
        c=-1;
            while(r<nums.size()){
                if(nums[r]==0){
                    c=r;
                    r++;
                }
                else{
                    l=c+1;
                    len=max(len,r-l+1);
                    r++;
                }
                
            }
            return len;
        }
        while(r<nums.size()){
            if(nums[r]==0 && k==0){
                l=v[c]+1;
                c=c+1;
                
                v.push_back(r);
                // cout<<"first pointer shift at "<<l<<endl;
            }
            else if(nums[r]==0 ){
                k--;
                v.push_back(r);
            }
            len=max(len,(r-l+1));
            // cout<<"the rear pointer at "<<r<<endl;
            r++;
        }
        return len;
    }
};