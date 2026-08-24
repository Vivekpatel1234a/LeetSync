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
    unordered_map<TreeNode*,TreeNode*>mp;
    TreeNode* init=NULL;
    void inorder(TreeNode* root, int start){
        if(root==NULL)return;
        if(root->val==start)init=root;
        if(root->left)mp[root->left]=root;
        inorder(root->left,start);
        if(root->right)mp[root->right]=root;
        inorder(root->right,start);
    }

    int amountOfTime(TreeNode* root, int start) {
        //use inorder or bfs(using queue) to store parent child relationship
        if(root->left==NULL && root->right==NULL)return 0;
        inorder(root,start);
        unordered_set<TreeNode*>st;
        queue<TreeNode*>q;
        q.push(init);
        st.insert(init);
        int k=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !st.count(temp->left)){
                    q.push(temp->left);
                    st.insert(temp->left);
                }
                if(temp->right && !st.count(temp->right)){
                    q.push(temp->right);
                    st.insert(temp->right);
                }
                if(mp.count(temp) &&  !st.count(mp[temp])){
                    q.push(mp[temp]);
                    st.insert(mp[temp]);
                }              
            }
            k++;
        }
        return k-1;
    }
};