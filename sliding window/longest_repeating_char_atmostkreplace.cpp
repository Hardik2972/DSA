#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int len=0;
        int fixed=0;
        unordered_map<char,int> m;
        while(r<s.size()){
            m[s[r]]++;
            fixed=max(fixed,m[s[r]]);
            if(r-l+1-fixed>k){
                m[s[l]]--;
                l++;
            }
            len=max(len,(r-l+1));
            r++;
        }
        return len;
    }
};