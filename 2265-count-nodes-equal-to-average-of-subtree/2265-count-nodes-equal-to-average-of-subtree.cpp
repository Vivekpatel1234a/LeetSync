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
    unordered_map<TreeNode*,int>mp;
    int ans=0;
    int solve(TreeNode* root){
        if(root==NULL)return 0;
        mp[root]=root->val;
        root->val=root->val+solve(root->left)+solve(root->right);
        return root->val;
    }

    int count(TreeNode* root){
        if(root==NULL)return 0;
        int cnt=1+count(root->left)+count(root->right);
        int res=(root->val/cnt);
        if(res==mp[root])ans++;
        return cnt;
    }

    int averageOfSubtree(TreeNode* root) {
         solve(root);
         count(root);
         return ans; 
    }
};