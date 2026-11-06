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
    int d1=0;
    int d2=0;
    TreeNode* p1=NULL;
    TreeNode* p2=NULL;
    int x1;
    int y1;
    void solve(TreeNode* root, int d){
        if(root==NULL)return;
        if(root->left && root->left->val==x1){
            p1=root;
            d1=d;
        }
        if(root->left && root->left->val==y1){
            p2=root;
            d2=d;
        }
        if(root->right && root->right->val==x1){
            p1=root;
            d1=d;
        }
        if(root->right && root->right->val==y1){
            p2=root;
            d2=d;
        }
        solve(root->left,d+1);
        solve(root->right,d+1);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        x1=x;
        y1=y;
        solve(root,0);
        if(d1!=d2 || p1==p2 || p1==NULL || p2==NULL) return 0;
        return 1;
    }
};