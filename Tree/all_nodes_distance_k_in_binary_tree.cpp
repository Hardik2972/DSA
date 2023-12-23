#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    void print(queue<TreeNode*> q){
        while(!q.empty()){
            cout<<q.front()->val<<"  ";
            q.pop();
        }
        cout<<endl;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root) return ans;
//************************** it is done to convert the tree into graph by adding the map**************************
        unordered_map<TreeNode*,TreeNode*> m;
        queue<TreeNode*> q;
        q.push(root);
        int length = 0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                length++;
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    m[temp->left]=temp;
                }
                if(temp->right){
                    q.push(temp->right);
                    m[temp->right]=temp;
                }
            }
        }
        //later part is used to solve the question part 
        q.push(target);
        int level = 0;
        unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        while(!q.empty()){
            print(q);
            int size = q.size();
            if(level++==k) break;
            for(int i =0 ;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left && !visited[temp->left]) {
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right]=true;
                }
                if(m.find(temp)!=m.end() && !visited[m[temp]]) {
                    q.push(m[temp]);
                    visited[m[temp]]=true;
                }
            }
            
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};