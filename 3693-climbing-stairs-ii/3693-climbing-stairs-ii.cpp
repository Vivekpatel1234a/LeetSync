class Solution {
public:
    int dp[100001];
    long long solve(int i,vector<int>& costs){
        int n=costs.size();
        if(dp[i]!=-1)return dp[i];
        if(i==n)return 0;
        int mini=INT_MAX;
        if(i+1<=n){
            int ans=costs[i+1-1]+1+solve(i+1,costs);
            mini=min(mini,ans);
        }
        if(i+2<=n){
            int ans=costs[i+2-1]+4+solve(i+2,costs);
              mini=min(mini,ans);
        }
        if(i+3<=n){
            int ans=costs[i+3-1]+9+solve(i+3,costs);
              mini=min(mini,ans);
        }
        return dp[i]=mini;
    }
    int climbStairs(int n, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0,costs);
    }
};