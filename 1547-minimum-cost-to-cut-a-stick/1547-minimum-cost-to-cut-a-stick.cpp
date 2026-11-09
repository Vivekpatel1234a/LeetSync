class Solution {
public:
    int solve(int i, int j, vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MAX;
        for(int k=i; k<=j; k++){
            int step=cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
            mini=min(mini,step);
        }
        return dp[i][j]=mini;
    }

    int minCost(int n, vector<int>& cuts){
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int sz=cuts.size();
        vector<vector<int>>dp(sz+1,vector<int>(sz+1,-1));
        return solve(1,cuts.size()-2,cuts,dp);
    }
};