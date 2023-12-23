#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

class Solution {
  public:
    bool isHeap(struct Node* tree) {
        
        // 1st condition tree should be complete
        // 2nd condition parent is greater than the child
        
        bool ans = true;
        if(!tree) return true;
        queue<Node*> q;
        q.push(tree);
        
        // flag used to check whether the tree is complete or not
        
        bool flag = false;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(!temp->left) flag = true;
            else if(!flag){
                q.push(temp->left);
                if(temp->data<temp->left->data){
                    return false;
                    
                }
            }
            else if(flag) return false;
            if(!temp->right) flag = true;
            
            else if(!flag){
                q.push(temp->right);
                if(temp->data<temp->right->data){
                    return false;
                    
                }
            }
            else if(flag) return false;
        }
        return ans;
    }
};