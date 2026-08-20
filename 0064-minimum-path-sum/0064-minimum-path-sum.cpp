class Solution {
public:
    int dp[201][201];

    int solve(int i, int j, int m, int n,vector<vector<int>>&grid){
        if(dp[i][j]!=-1)return dp[i][j];
        int ans1=1e7;
        int ans2=1e7;
        if(i==m-1 && j==n-1){
            return grid[m-1][n-1];
        }
        if(i+1<m){
            ans1=solve(i+1,j,m,n,grid)+grid[i][j];
        }
        if(j+1<n){
            ans2=solve(i,j+1,m,n,grid)+grid[i][j];
        }
        return dp[i][j]=min(ans1,ans2);
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m=grid.size();
        int n=grid[0].size();
        int ans=solve(0,0,m,n,grid);
        return ans;
    }
};