/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        return levelOrder(root);
    }

    vector<int> levelOrder(TreeNode* root) {
             vector<int>level;
        if(!root)return level;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto it=q.size();
            TreeNode *r=q.front();
                level.push_back(r->val);
            for(int i=0;i<it;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->right)q.push(node->right);
                if(node->left)q.push(node->left);
            }
        }return level;
    }
};
