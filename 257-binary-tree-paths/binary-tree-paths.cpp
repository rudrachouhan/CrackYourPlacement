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

    void solve(TreeNode* node,string m,vector<string> &ans){
        if (node != NULL) {

            if (m == "") m += to_string(node->val);
            else m += ("->" + to_string(node->val));

            // add string to result if current node is a leaf
            if (node->left == nullptr && node->right == nullptr) ans.emplace_back(m);

            if (node->left) solve(node->left, m, ans);
            if (node->right) solve(node->right, m, ans);
        }

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string mid = "";
        vector<string> ans;
        solve(root,mid,ans);
        return ans;
    }
};