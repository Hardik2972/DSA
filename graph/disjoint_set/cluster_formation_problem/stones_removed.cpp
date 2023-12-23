//*********************************question*******************************************
// 947. Most Stones Removed with Same Row or Column
// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest
// possible number of stones that can be removed.

// Example 1:

// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5

// *************************hint**********************************
// Let us assume that the number of given stones is "num"
// If we look at all the stone clusters connected to one another, what is the number of stones that you can remove?
// Example : In the below given grid, if '0' represents stones
// X X 0 X X
// 0 X 0 X X
// X X X X X
// 0 X X X 0

// We can map all the stones to one another using basic traversal algorithms.
// For EACH SUCH CLUSTER of stones that can be connected in the grid, the number of stones that can be removed is number of stones in that cluster - 1.

// If we now add the number of clusters and all the number of stones that can be remove :-
// (Stones in Cluster 1- 1) + (C2 -1) + (C3 -1) + ......
// = C1 + C2 + C3 +..... - (number of clusters)
// = Total number of stones - Number of Clusters

// *****************************solution**********************************
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
class DisjointSet{
    public:
    vector<int> size,parent;
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }
    void unionBySize(int u,int v){
        int upu=findParent(u);
        int upv=findParent(v);
        if(upu==upv) return;
        if(size[upu]<size[upv]){
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else{
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
    }

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        map<vector<int>,int> m;
        DisjointSet set(stones.size());
        for(int i=0;i<stones.size();i++){
            for(int j=0;j<2;j++){
                vector<int> search={j,stones[i][j]}; 
                if(m.find(search)==m.end()) m[search]=i;
                else{
                    set.unionBySize(i,m[search]);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<stones.size();i++){
            if(i==set.parent[i]) ans++;
        }
        return stones.size()-ans;
    }
};