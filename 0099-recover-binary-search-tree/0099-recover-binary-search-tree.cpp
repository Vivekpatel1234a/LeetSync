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
    TreeNode* prevmax=new TreeNode(INT_MIN);
    TreeNode* nextmin=new TreeNode(INT_MIN);
    int mini=INT_MIN;
    bool flag=false;
   void solve(TreeNode* root){
        if(root==NULL)return;
        solve(root->left);
        if(root->val>mini && flag==false){
            prevmax=root;
            mini=root->val;
        }
        else if(root->val<mini){
            mini=root->val;
            nextmin=root;
            flag=true;
        }
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        int temp=prevmax->val;
        prevmax->val=nextmin->val;
        nextmin->val=temp;
        return ;
    }
};