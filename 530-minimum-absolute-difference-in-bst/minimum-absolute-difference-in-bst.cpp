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

    void inorder(TreeNode* root,vector<int> &v){
        if(root==NULL)
        return ;

        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        inorder(root,v);

        int i = 0;
        int j = 1;
        int mini = INT_MAX;
        while(j<v.size()){
            mini = min(mini, abs(v[j]-v[i]));
            i++;
            j++;
        }
        return mini;
        
    }
};