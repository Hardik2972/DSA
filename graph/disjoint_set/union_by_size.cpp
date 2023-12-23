#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n){
      size.resize(n+1,1);
      parent.resize(n+1);
      for(int i=0;i<=n;i++){
        parent[i]=i;
      }
    }

    int findParent(int u){
        if(parent[u]==u) return u;
        else{
            return parent[u]=findParent(parent[u]);
        }
    }

    void unionByRank(int u,int v){
        int uParentU=findParent(u);
        int uParentV=findParent(v);
        if(uParentU==uParentV) return ;
        if(size[uParentU]<size[uParentV]){
            parent[uParentU]=uParentV;
            size[uParentV] += size[uParentU];
        }
        else if(size[uParentU]>=size[uParentV]){
            parent[uParentV]=uParentU;
            size[uParentU] += size[uParentV];
        }
    }
      
};

int main(){
    DisjointSet set(7);
    set.unionByRank(1,2);
    set.unionByRank(2,3);
    set.unionByRank(4,5);
    set.unionByRank(6,7);
    set.unionByRank(5,6);
    if(set.findParent(3)==set.findParent(7)) cout<<"yes";
    else{
        cout<<"No"<<endl;
    }
    set.unionByRank(3,7);
    if(set.findParent(3)==set.findParent(7)) cout<<"yes";
    else{
        cout<<"No"<<endl;
    }
}