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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>result;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,vector<pair<int,int>>>mp;
        while(!q.empty()){
            auto[node,it]=q.front();
            q.pop();
            int dist=it.first;
            int height=it.second;
            mp[dist].push_back({height,node->val});
            if(node->left){
                q.push({node->left,{dist-1,height+1}});

            }
            if(node->right){
                q.push({node->right,{dist+1,height+1}});
            }
        }
        for(auto it:mp){
           sort(it.second.begin(),it.second.end());
           vector<int>temp;
            for(auto ele:it.second)temp.push_back(ele.second);
            result.push_back(temp);
        }
    return result;
    }
};