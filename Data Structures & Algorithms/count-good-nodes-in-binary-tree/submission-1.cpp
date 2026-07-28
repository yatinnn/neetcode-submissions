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
    int goodNodes(TreeNode* root) {
        
        if(!root)return 0;
        int cnt=0;
        f(root,-1e9,cnt);
        return cnt;
    }

void  f(TreeNode * root,int maxVal,int &cnt){
        if(root->val>=maxVal){
            cnt++;
            maxVal=root->val;
        }
        if(root->left)f(root->left,maxVal,cnt);
        if(root->right)f(root->right,maxVal,cnt);

    }
};
