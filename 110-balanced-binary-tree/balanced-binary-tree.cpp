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

    int solve(TreeNode* root){
        if(!root)
        return NULL;

        int l = solve(root->left);
        int r = solve(root->right);

        return max(l,r)+1;
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        return true;

        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);

        int lH = solve(root->left);
        int rH = solve(root->right);

        if(abs(lH-rH)>1) return false;
        return (l && r);
    }
};