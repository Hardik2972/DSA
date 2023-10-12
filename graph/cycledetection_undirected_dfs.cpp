#include<iostream>
#include<queue>
#include<utility>
using namespace std;
class Solution {
  public:
  
    bool dfs(int src,vector<int> adj[],vector<int> &vis,int parent){
        vis[src]=1;
        for(int i=0;i<adj[src].size();i++){
            if(adj[src][i]!=parent){
                if(vis[adj[src][i]]!=0) return true;
                else{
                    if(dfs(adj[src][i],adj,vis,src)) return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis,-1)) return true;
            }
        }
        return false;
    }
};