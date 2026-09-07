//DFS from every gold cell, try all 4 directions while marking cells visited, and backtrack after each path. Take the maximum gold collected.
class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int solve(int i, int j, vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n || i<0 || j<0 ||grid[i][j]==0)return 0;
        int gold=grid[i][j];
        grid[i][j]=0;
        int best=0;
        for(int k=0; k<4; k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=m || y>=n || x<0 || y<0)continue;
            best=max(best,solve(x,y,grid)); 
        }
        grid[i][j]=gold;
        return gold+best;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       int cost=0;
       for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]!=0){
                cost=max(cost,solve(i,j,grid));
            }
        }
       }
       return cost;
    }
};