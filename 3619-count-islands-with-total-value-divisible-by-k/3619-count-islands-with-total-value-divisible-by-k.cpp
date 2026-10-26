class Solution {
public:
int m,n;
    long long solve(int i, int j, vector<vector<int>>& grid){
       if(i<0 || j<0 || i==m || j==n)return 0;
       long long ans=grid[i][j];
       grid[i][j]=0;
        if(i+1<m && grid[i+1][j])ans+=solve(i+1,j,grid);
        if(j+1<n && grid[i][j+1])ans+=solve(i,j+1,grid);
        if(i-1>=0 && grid[i-1][j])ans+=solve(i-1,j,grid);
        if(j-1>=0 && grid[i][j-1])ans+=solve(i,j-1,grid);
        return ans;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
       int cnt=0;
       for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]!=0){
                long long ans=solve(i,j,grid);
                if(ans%k==0)cnt++;
            }
        }
       }
       return cnt; 
    }
};