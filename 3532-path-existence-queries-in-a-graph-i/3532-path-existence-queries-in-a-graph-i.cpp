class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int sz=queries.size();
        vector<int>parent(n);
        vector<bool>ans;
        int par=1;
        parent[0]=1;
        for(int i=0; i<n-1; i++){
            if(abs(nums[i]-nums[i+1])<=maxDiff){
                parent[i+1]=par;
            }
            else{
                par++;
                parent[i+1]=par;
            }
        }
        for(int i=0; i<sz; i++){
            if(parent[queries[i][0]]==parent[queries[i][1]]){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        

        return ans;
    }
};