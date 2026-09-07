class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&vis){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n || i<0 || j<0 || vis[i][j] || grid[i][j]==0)return 0;
        vis[i][j]=1;
        //cout<<i<<" "<<j<<"   ";
        int ans=grid[i][j]+max({solve(i+1,j,grid,vis),solve(i,j+1,grid,vis),solve(i-1,j,grid,vis),solve(i,j-1,grid,vis)});
        vis[i][j]=0;
        return ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>>vis(m,vector<int>(n,0));
       int cost=0;
       for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]!=0){
                //cout<<i<<" "<<j<<" -> ";
                cost=max(cost,solve(i,j,grid,vis));
            }
        }
       }
       return cost;
    }
};