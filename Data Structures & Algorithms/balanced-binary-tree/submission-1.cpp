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
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int h=0;
        return maxDepth(root,h);

    }
    bool maxDepth(TreeNode* root,int& h) {
        if(!root){
            h=0;
            return true;
        }
        int l=0;
        int r=0;
        if (!maxDepth(root->left, l))
            return false;

        if (!maxDepth(root->right, r))
            return false;
        if(abs(l-r)>1)return false;

        h= 1 + max (l , r);
        return true;
    }
};
