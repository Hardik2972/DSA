// ********************************************question************************************************
// 721. Accounts Merge
// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name,
// they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

// Example 1:

// Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"]
// ,["John","johnsmith@mail.com","john00@mail.com"]
// ,["Mary","mary@mail.com"]
// ,["John","johnnybravo@mail.com"]]


// Output: [["John","john00@mail.com","john_newyork@mail.com"
// ,"johnsmith@mail.com"]
// ,["Mary","mary@mail.com"]
// ,["John","johnnybravo@mail.com"]]

// *********************************************solution*****************************************
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int> m;
        DisjointSet set(accounts.size());
        // main code for cluster formation 
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string checker = accounts[i][j];
                if(m.find(checker)==m.end()) m[checker]=i;
                else{
                    set.unionBySize(i,m[checker]);
                }
            }
        }
        
        vector<vector<string>> mergedMail(accounts.size());
        for(auto it:m){
            mergedMail[set.findParent(it.second)].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(int i=0;i<(accounts.size());i++){
            if(mergedMail[i].size()==0) continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(int j=0;j<mergedMail[i].size();j++){
                temp.push_back(mergedMail[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
       
        return mergedMail;
    }
};