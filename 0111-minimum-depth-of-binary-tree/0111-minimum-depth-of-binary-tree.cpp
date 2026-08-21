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
    int mini=INT_MAX;
    void solve(TreeNode* root,int d){

        if(root->left==NULL && root->right==NULL){
            mini=min(mini,d);
            return;
        }
      if(root->left)  solve(root->left,d+1);
      if(root->right)  solve(root->right,d+1);

    }
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        solve(root,1);
        return mini;
    }
};