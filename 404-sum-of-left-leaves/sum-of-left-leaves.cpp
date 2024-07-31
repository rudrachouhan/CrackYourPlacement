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

    void solve(TreeNode* root,int &count,bool l){
        if(root==NULL)
        return;
        if(root->left==NULL && root->right==NULL && l==true){
            count+=root->val;
        }
        solve(root->left,count,true);
        solve(root->right,count,false);

    }

    int sumOfLeftLeaves(TreeNode* root) {
        bool leftCall = true;
        int count = 0;
        if(root->left==NULL && root->right==NULL)
        return count;
        solve(root,count,leftCall);
        return count;
    }
};