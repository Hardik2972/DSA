#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    void dfs(int i,int parent,int timer,vector<int>& vis,vector<int>& low,vector<int>& disc,vector<int> adj[],vector<int>& result){
        vis[i]=1;
        low[i]=disc[i]=timer++;
        int child = 0;
        for(int j=0;j<adj[i].size();j++){
            if(parent!=adj[i][j]){
                if(vis[adj[i][j]]){
                    low[i]=min(low[i],disc[adj[i][j]]);
                }
                else{
                    dfs(adj[i][j],i,timer,vis,low,disc,adj,result);
                    low[i]=min(low[i],low[adj[i][j]]);
                    if(low[adj[i][j]]>=disc[i] && parent!=-1){
                        result[i]=1;
                    }
                    child++;
                }
            }
        }
        if(child>1 && parent ==-1){
            result[i]=1;
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> result(V);
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        int timer = 0;
        vector<int> vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,timer,vis,low,disc,adj,result);        
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(result[i]){
            ans.push_back(i);}
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};