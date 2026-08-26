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
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
         while(root){
            st.push(root);
            root=root->left;
         }
    }
    
    int next() {
        int x=st.top()->val;
        TreeNode* node=st.top();
        st.pop();
        if(node->right){
           TreeNode* temp=node->right;
            while(temp){
                st.push(temp);
                temp=temp->left;
            }
        }
        return x;
    }
    
    bool hasNext() {
        //st.pop();
        return st.size();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */