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

    bool solve(TreeNode* root,int t,int count){
        if(root==NULL)
        return false;

        if(root->left==NULL && root->right==NULL){
            if(t==count+root->val)
            return true;
        }

        bool leftAns = solve(root->left,t,count+root->val);
        bool rightAns = solve(root->right,t,count+root->val);

        return (leftAns || rightAns);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int count = 0;
        bool ans = solve(root,targetSum,count);
        return ans;
    }
};