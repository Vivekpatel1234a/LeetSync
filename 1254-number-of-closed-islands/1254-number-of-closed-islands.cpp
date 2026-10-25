class Solution {
public:
int m,n;

    void markx(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0 || i==m || j==n)return;
        grid[i][j]=-1;
        if(i+1<m && grid[i+1][j]==0){
            markx(i+1,j,grid);
        }
        if(i-1>=0 && grid[i-1][j]==0){
            markx(i-1,j,grid);
        }
        if(j+1<n && grid[i][j+1]==0){
            markx(i,j+1,grid);
        }
        if(j-1>=0 && grid[i][j-1]==0){
            markx(i,j-1,grid);
        }

    }

    int solve(int i , int j, vector<vector<int>>& grid){
        if((i==0 || j==0 || i==m-1 || j==n-1))return 0;
        grid[i][j]=-1;
        if(i+1<m && grid[i+1][j]==0){
           if(solve(i+1,j,grid)==0)return 0;
        }
        if(i-1>=0 && grid[i-1][j]==0){
            if(solve(i-1,j,grid)==0)return 0;
        }
        if(j+1<n && grid[i][j+1]==0){
            if(solve(i,j+1,grid)==0)return 0;
        }
        if(j-1>=0 && grid[i][j-1]==0){
            if(solve(i,j-1,grid)==0)return 0;
        }
        return 1;        
    }

    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0; i<m; i++){
            if(i==0 || i==m-1){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    markx(i,j,grid);
                    //cout<<i<<" "<<j<<"   "; 
                }
            }
            }
            else{
                if(grid[i][0]==0){
                    markx(i,0,grid);
                    //cout<<i<<" "<<0<<"   "; 
                }
                if(grid[i][n-1]==0){
                    markx(i,n-1,grid);
                    //cout<<i<<" "<<n-1<<"   "; 
                }
            }
        }
        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    if(solve(i,j,grid)) cnt++;;
                }
            }
        }
        return cnt;
    }
};