#include<iostream>
#include<queue>
#include<utility>
using namespace std;
class Solution {
public:
    bool dfs(int src,vector<vector<int>> graph,vector<int> &color,int parentColor,int parent){
        int todoColor=!parentColor;
        for(int i=0;i<graph[src].size();i++){
             if(graph[src][i]!=parent){
                if(color[graph[src][i]]==parentColor) return false;
                else{
                    if(color[graph[src][i]]==-1){
                        color[graph[src][i]]=todoColor;
                        if(!dfs(graph[src][i],graph,color,todoColor,src)) {
                            // cout<<graph[src][i]<<endl;
                            return false;
                        }
                    }
                }
             }
        }
        return true;
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(i,graph,color,0,-1)) {cout<<i<<endl; return false;}
            }
        }
        return true;
    }
};