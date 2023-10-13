#include<iostream>
#include<queue>
#include<utility>
#include<stack>
using namespace std;
class Solution
{
	public:
	void dfs(int src,vector<int> adj[],int vis[],stack<int> &st){
	    vis[src]=1;
	    for(int i=0;i<adj[src].size();i++){
	        if(vis[adj[src][i]]==0){
	            dfs(adj[src][i],adj,vis,st);
	        }
	    }
	    st.push(src);
	    return ;
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V]={0};
	    stack<int> ans;
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            dfs(i,adj,vis,ans);
	        }
	    }
	    vector<int> ans1;
	    while(!ans.empty()){
	        ans1.push_back(ans.top());
	        ans.pop();
	    }
	    return ans1;
	}
};