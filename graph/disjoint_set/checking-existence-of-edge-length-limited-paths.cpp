// ***********************************************Question*******************************************
// Checking Existence of Edge Length Limited Paths
// An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] 
// denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.

// Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether 
// there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .

// Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is 
// a path for queries[j] is true, and false otherwise.

 

// Example 1:

// Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
// Output: [false,true]
// ****************************************Code*************************************************

// special topics - two pointers,unionfind,sort
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
class DSU{
    public:
      vector<int> parent;
      vector<int> size;
      DSU(int n){
          parent.resize(n);
          size.resize(n,1);
          for(int i=0;i<n;i++){
              parent[i]=i;
          }
      }
      int find(int u){
          if(u==parent[u]) return u;
          return parent[u]=find(parent[u]);
      }
      void Union(int u,int v){
          u = find(u);
          v = find(v);
          if(u!=v){
              if(u>v) swap(u,v);
              parent[u]=v;
              size[v]+=size[u];
          }
      }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[](vector<int>& a,vector<int>& b){
           return a[2]<b[2];
        });
        sort(edgeList.begin(),edgeList.end(),[](vector<int>& a,vector<int>& b){
            return a[2]<b[2];
        });
        vector<bool> ans(queries.size(),false);
        int i= 0;
        int j=0;
        DSU obj(n);
        while(i<queries.size()){
            int limits = queries[i][2];
            while(j<edgeList.size() && limits>edgeList[j][2]){
                obj.Union(edgeList[j][0],edgeList[j][1]);
                j++;
            }
            if(obj.find(queries[i][0])==obj.find(queries[i][1])){
                ans[queries[i][3]]=true;
            }
            i++;
        }
        return ans;
    

    }
};