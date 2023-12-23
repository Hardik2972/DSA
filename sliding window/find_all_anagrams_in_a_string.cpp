#include<iostream>
#include<unordered_map>
using namespace std;
//*****************************************Question**************************************************
// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// ******************************question of fixed window size****************************************


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> p_hash(26,0);
        vector<int> s_hash(26,0);
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        if(n<m) return {};
        for(int i = 0;i<m;i++){
            p_hash[p[i]-'a']++;
            s_hash[s[i]-'a']++;
        }
        if(p_hash==s_hash) ans.push_back(0);
        for(int i=m;i<n;i++){
            s_hash[s[i-m]-'a']--;
            s_hash[s[i]-'a']++;
            if(s_hash==p_hash) ans.push_back(i-m+1);
        }
        return ans;
    }
};