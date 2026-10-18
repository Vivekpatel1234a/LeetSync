class Solution {
public:
    pair<int,int>solve(int i, int j, vector<vector<char>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(grid[i][j]=='L'){
            if(j==0 || grid[i][j-1]=='.')return {i,j};
            grid[i][j]='.';
            return solve(i,j-1,grid);
        }
        else if(grid[i][j]=='R'){
            if(j+1==n || grid[i][j+1]=='.')return {i,j};
            grid[i][j]='.';
            return solve(i,j+1,grid);
        }
        else if(grid[i][j]=='D'){
            if(i+1==m || grid[i+1][j]=='.')return {i,j};
            grid[i][j]='.';
            return solve(i+1,j,grid);
        }
        else if(grid[i][j]=='U'){
            if(i==0 || grid[i-1][j]=='.')return {i,j};
            grid[i][j]='.';
            return solve(i-1,j,grid);
        }  
        return {0,0}; 
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
    pair<int,int>ans=solve(0,0,grid);
    return {ans.first,ans.second};
    }
};