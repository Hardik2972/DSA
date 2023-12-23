#include<iostream>
#include<queue>
#include<utility>
using namespace std;

//prims algorithm is greedy algo
// 1. pickup any vertex 
// 2. put edges in the priority queue take the least among them 
// 3. remeber mark visited the node only when you when you taking it from top of queue not when you puch it 
// 4. always check node is visited or not before adding sum+=weight


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // space complexity O(edges)
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        // q{weight,node_value}

        q.push({0,0});
        vector<int> vis(V,0);
        int sum = 0;

        // time complexity O(E)
        while(!q.empty()){
            int dist = q.top().first;
            int node = q.top().second;
            // T.C. O(Log(e)) of pop operation
            q.pop();
            if(vis[node]==1) continue;
            sum+=dist;
            vis[node] = 1;
            //T.C O(E)
            for(auto it:adj[node]){
                if(vis[it[0]]==0){
                    // time complexity O(log(E))
                    q.push({it[1],it[0]});
                }
            }
        }
        return sum;
    }
};

//t.c Oe.loge + O(e.loge) ~ O(E.log(E));
//sc o(e)+ o(v)