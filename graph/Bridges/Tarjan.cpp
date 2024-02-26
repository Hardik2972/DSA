#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void dfs(int i,int& timer,int parent,vector<int>& disc,vector<int>& low,vector<int> adj[],vector<int>& vis,auto& result){
        vis[i]=true;
        disc[i]=low[i]=timer++;
        for(int j=0;j<adj[i].size();j++){
            if(parent!=adj[i][j]){
                if(vis[adj[i][j]]){
                    // backEdge case 
                    low[i]=min(low[i],disc[adj[i][j]]);
                }
                else{
                    dfs(adj[i][j],timer,i,disc,low,adj,vis,result);
                    low[i]=min(low[adj[i][j]],low[i]);
                    // check whether the bridge exist or not 
                    if(low[adj[i][j]]>disc[i]){
                        vector<int> ans;
                        ans.push_back(i);
                        ans.push_back(adj[i][j]);
                        sort(ans.begin(),ans.end());
                        result.push_back(ans);
                    }
                }
            }
        }
    }
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    vector<vector<int>> result;
	    vector<int> disc(v,-1);
	    vector<int> low(v,-1);
	    vector<int> vis(v,0);
	    int timer = 0;
	    for(int i=0;i<v;i++){
	        if(!vis[i]){
	            dfs(i,timer,-1,disc,low,adj,vis,result);
	        }
	    }
	    sort(result.begin(),result.end());
	    return result;
	}
};