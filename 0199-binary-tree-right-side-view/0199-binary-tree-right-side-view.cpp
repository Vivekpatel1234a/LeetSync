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
   void rs(TreeNode* root, vector<int>&v, int& target,int i,int& maxi){
    if(root==NULL) return;
    if(maxi==i){
    cout<<root->val<<" ";
    v.push_back(root->val);
    maxi=i+100;
    
    }
    rs(root->right,v,target,i+1,maxi);
    rs(root->left,v,target,i+1,maxi);

   }

    int height(TreeNode* root){
        if(root==NULL) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        
            return 1+max(lh,rh);
        
    return 0;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        int h=height(root);
       // cout<<h<<" - height"<<endl;
        for(int i=1; i<=h; i++){
            int maxi=i;
            rs(root,v,i,1,maxi);
            cout<<"\n";
        }
        return v;

    }
};