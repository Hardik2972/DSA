#include<iostream>
#include<queue>
#include<utility>
using namespace std;
class Solution {
  public:
  
    bool detect(int src,vector<int> adj[],vector<int> &vis){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src]=1;
        while(!q.empty()){
            pair<int,int> temp = q.front();
            q.pop();
            for(int i=0;i<adj[temp.first].size();i++){
                if(adj[temp.first][i]!=temp.second){
                    if(vis[adj[temp.first][i]]!=0) return true;
                    else{
                        vis[adj[temp.first][i]]=1;
                        q.push({adj[temp.first][i],temp.first});
                    }
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
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
    }
};