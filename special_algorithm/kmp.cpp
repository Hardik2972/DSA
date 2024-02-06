#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution
{
    public:
    vector<int> get_lps(string s) {
	    vector<int> prefix(s.size(),0);
	    int i=0;
	    int j=1;
	    while(j<s.size()){
	        if(s[i]==s[j]){
	            prefix[j]=i+1;
	            j++;i++;
	        }
	        else{
	            if(i==0){
	                prefix[j]=0;
	                j++;
	            }
	            else{
	                i=prefix[i-1];
	            }
	        }
	    }
	    return prefix;
	}
        vector <int> search(string pat, string txt)
        {
            vector<int> lps = get_lps(pat);
            int first = 0;
            int second = 0;
            vector<int> ans;
            while(first<txt.size()){
                
                if(txt[first]==pat[second]){
                    second++;
                    first++;
                }
                else{
                    if(second==0){
                        first++; 
                    }
                    else{
                        second = lps[second-1];
                    }
                }
                if(second==pat.size()){
                    ans.push_back(first-second+1);
                    second = lps[second-1];
                }
            }
            return ans;
        }
     
};