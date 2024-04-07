// ***************************************question*****************************************
// 2516. Take K of Each Character From Left and Right
// You are given a string s consisting of the characters
// 'a', 'b', and 'c' and a non-negative integer k. Each minute, 
// you may take either the leftmost character of s, or the rightmost character of s.
// Return the minimum number of minutes needed for you to take at least k of each
// character, or return -1 if it is not possible to take k of each character.

// Example 1:

// Input: s = "aabaaaacaabc", k = 2
// Output: 8
// *********************************code***********************************************

#include<iostream>
#include<string>
#include<utility>
#include<vector>
using namespace std;
class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> left(3,0);
        vector<int> right(3,0);
        int n = s.size();
        if(k==0) return 0;
        for(int i=0;i<s.size();i++){
            left[s[i]-'a']++;
        }
        int ans = INT_MAX;
        int i=s.size()-1;
        int j=s.size();
        while(i>=-1){
            int aCount = left[0] + right[0];
            int bCount = left[1] + right[1];
            int cCount = left[2] + right[2];
            while(j>i+1 && j>=1 && (aCount<k || bCount<k || cCount<k)){
                j--;
                right[s[j]-'a']++;
                aCount = left[0] + right[0];
                bCount = left[1] + right[1];
                cCount = left[2] + right[2];
            }
            if(aCount>=k && bCount>=k && cCount>=k){
            ans = min(ans,(i+1+n-j));
            }
            if(i>=0)
            left[s[i]-'a']--;
            i--;
        }
        return ans==INT_MAX?-1:ans;
    }
};