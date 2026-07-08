class Solution {
public:

    void solve(vector<vector<int>>&ans, int i, vector<int>&candidates, int target,int sum,vector<int>temp){
        int n=candidates.size();
        if(sum>target){
            return;
        }
        if(sum==target){
            ans.push_back(temp);
        }
        for(int k=i; k<n; k++){
            temp.push_back(candidates[k]);
            solve(ans,k,candidates,target,sum+candidates[k],temp);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int sum=0;
        vector<int>temp;
        solve(ans,0,candidates,target,sum,temp);
        return ans;
    }
};