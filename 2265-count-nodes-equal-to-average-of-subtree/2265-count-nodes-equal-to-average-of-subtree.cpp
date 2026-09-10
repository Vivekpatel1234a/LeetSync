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
    int ans=0;
    pair<int,int>solve(TreeNode* root){
        if(root==NULL)return {0,0};
        auto lt=solve(root->left);
        auto rt=solve(root->right);
        int total=lt.first+rt.first+root->val;
        int cnt=lt.second+rt.second+1;
        if(total/cnt==root->val)ans++;
        return {total,lt.second+rt.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
         solve(root);
         return ans;
    }
};

/*class Solution {
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
};*/