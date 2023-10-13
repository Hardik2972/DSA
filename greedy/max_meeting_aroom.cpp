#include <iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b ){
            return a.second<b.second;
}

class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
       vector<pair<int,int>> temp;
       for(int i=0;i<n;i++){
           temp.push_back({start[i],end[i]});
       }
       sort(temp.begin(),temp.end(),cmp);
       int last=0;
       int ans=0;
       for(int i=0;i<n;i++){
           if(temp[i].first>last){
               ans++;
               last=temp[i].second;
           }
       }
       return ans;
    }
};