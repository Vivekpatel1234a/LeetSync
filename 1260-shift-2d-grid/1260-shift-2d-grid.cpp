class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       int m=grid.size();
       int n=grid[0].size();
       while(k--){
        vector<vector<int>> newarr(m,vector<int>(n,0));
       for(int i=0; i<m; i++){
        for(int j=0; j<n-1; j++){
       newarr[i][(j+1)%n]=grid[i][j];
       }
       newarr[(i+1)%m][0]=grid[i][n-1];
       }
       newarr[0][0]=grid[m-1][n-1];
       grid=newarr;
       }
       return grid; 
    }
};