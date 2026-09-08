class Solution {
public:
    set<vector<int>>finalans;
    void solve(int idx, vector<int>& candidates, int target,vector<int>& ans){
        if(target==0){
            finalans.insert(ans);
            return;
        }
        if(idx>=candidates.size() || target<0)return;
        ans.push_back(candidates[idx]);
        solve(idx+1,candidates,target-candidates[idx],ans);
        ans.pop_back();
        while(idx+1<candidates.size() && candidates[idx]==candidates[idx+1]){
            idx++;
        }
        solve(idx+1,candidates,target,ans);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>ans;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,ans);
        vector<vector<int>>result;
        for(auto it:finalans)result.push_back(it);
        return result;
    }
};