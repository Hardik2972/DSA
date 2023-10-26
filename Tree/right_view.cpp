#include <iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front().first;
                int level = q.front().second;
                q.pop();
                if(temp->left!=NULL) q.push({temp->left,level+1});
                if(temp->right!=NULL) q.push({temp->right,level+1});
                if(i==size-1) ans.push_back(temp->val);
            }
        }
        return ans;
    }
};