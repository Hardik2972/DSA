#include<iostream>
#include<string>
#include<utility>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string st) {
    int size=st.size();
    int l=0;
    int r=0;
    int len=0;
    vector<int> v(256,-1);
    while(r<size){
        if(v[st[r]]!=-1){
            l=max(v[st[r]]+1,l);
        }
        len=max(len,r-l+1);
        v[st[r]]=r;
        cout<<"the added is "<<st[r]<<endl;
        r=r+1;
    
    }
    return len;
}