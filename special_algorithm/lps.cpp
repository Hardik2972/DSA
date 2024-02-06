#include<iostream>
#include<unordered_map>
using namespace std;
class Solution{
  public:		
	int lps(string s) {
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
	    return i;
	}
};