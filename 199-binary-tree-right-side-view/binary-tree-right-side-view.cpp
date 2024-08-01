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
        vector<int> ans;
        if(root==NULL)
        return ans;

        map<int,int> m;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));

        while(!q.empty()){
            pair<TreeNode*,int> p = q.front();
            q.pop();

            int f = p.first->val;
            int s = p.second;

            m[s] = f;

            if(p.first->left){
                q.push(make_pair(p.first->left,s+1));
            }
            if(p.first->right){
                q.push(make_pair(p.first->right,s+1));
            }
        }

        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};