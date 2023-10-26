#include <iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    vector<int> topView(Node *root)
    
    
    {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,int> m;
        while(!q.empty()){
            Node* temp = q.front().first;
            int tempLevel = q.front().second;
            if(m.find(tempLevel)==m.end()) m[tempLevel]=temp->data;
            q.pop();
            if(temp->left!=NULL){
                q.push({temp->left,tempLevel-1});
            }
            if(temp->right!=NULL){
                q.push({temp->right,tempLevel+1});
            }
        }
        
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }

};