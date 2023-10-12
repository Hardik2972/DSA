#include<iostream>
#include<queue>
#include<utility>
using namespace std;
class Solution {
  public:
    bool dfs(int src,vector<int> adj[],vector<int> &vis,vector<int> &pathVis,int parent){
        vis[src]=1;
        pathVis[src]=1;
        for(int i=0;i<adj[src].size();i++){
            //  if(adj[src][i]!=parent ){ because it is a directed graph we do not take care because it no goes back if it goes back than consider to be acycle
            if(vis[adj[src][i]]==1 && pathVis[adj[src][i]]==1) return true;
            else if(vis[adj[src][i]]==0){
                if(dfs(adj[src][i],adj,vis,pathVis,src)) return true;
            }
            //  }
            
        }
        pathVis[src]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis,pathVis,-1)) return true;
            }
        }
        return false;
    }
};