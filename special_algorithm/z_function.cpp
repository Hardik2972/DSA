#include<iostream>
#include<unordered_map>
using namespace std;
// ***************************************question********************************
// 3031. Minimum Time to Revert Word to Initial State II
// You are given a 0-indexed string word and an integer k.

// At every second, you must perform the following operations:

// Remove the first k characters of word.
// Add any k characters to the end of word.
// Note that you do not necessarily need to add the same characters that you removed. However, you must perform both operations at every second.

// Return the minimum time greater than zero required for word to revert to its initial state.

// Example 1:
// Input: word = "abacaba", k = 3
// Output: 2




class Solution {
public:
    vector<int> z_function(string word){
        int n = word.size();
        int l = 0;
        int r = 0;
        vector<int> z(n,0);
        for(int i=1;i<n;i++){
            // kickstart
            if(i<=r){
                z[i]=min(r-i+1,z[i-l]);
            }
            // extend
            while(i+z[i]<n && word[z[i]]==word[z[i]+i]) z[i]++;
            // extend circle 
            if(i+z[i]>r){
                l = i;
                r = z[i]+i-1;
            }
        }
        return z;
    }
    int minimumTimeToInitialState(string word, int k) {
        vector<int> z = z_function(word);
        int ans = 0;
        int start = 0;
        while(start<word.size()){
            start+=k;
            ans++;
            if(start<word.size() && z[start]>=(word.size()-start)) break;
        }
        return ans;
    }
};