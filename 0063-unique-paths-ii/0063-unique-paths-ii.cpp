class Solution {
public:
     int dp[101][101];
     int solve(int i, int j, int m , int n,vector<vector<int>>& grid){
        if(i>=m || j>=n)return 0;
        if(grid[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==m-1 && j==n-1)return 1;
        return dp[i][j]=solve(i+1,j,m,n,grid)+solve(i,j+1,m,n,grid);
     }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
     memset(dp,-1,sizeof(dp));
     int m=obstacleGrid.size();
     int n=obstacleGrid[0].size();
     int i=0;
     int j=0;
     int ans=solve(i,j,m,n,obstacleGrid);
     return ans;
    }
};