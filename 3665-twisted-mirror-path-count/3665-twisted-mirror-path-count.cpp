class Solution {
public:
    int m,n;
    int dp[500][500][2];
    int mod=1e9+7;
    int solve(int i, int j, int dir, vector<vector<int>>& grid){
        if(i==m-1 && j==n-1)return 1;
        else if(i==m || j==n)return 0;
        if(dp[i][j][dir]!=-1)return dp[i][j][dir];
        if(grid[i][j]==0){
            return dp[i][j][dir]=(solve(i+1,j,1,grid)+solve(i,j+1,0,grid))%mod;
        }
        else{
            if(dir==1){
                return dp[i][j][dir]=(solve(i,j+1,0,grid))%mod;
            }
            else{
                return dp[i][j][dir]=(solve(i+1,j,1,grid))%mod;
            }
        }
        return 0;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,grid);
    }
};