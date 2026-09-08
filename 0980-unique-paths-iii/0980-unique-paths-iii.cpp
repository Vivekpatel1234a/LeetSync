class Solution {
public:
    int cnt=0;
    int ans=0;
    int dirx[4]={0,1,0,-1};
    int diry[4]={1,0,-1,0};
    void solve(int i, int j, int endi,int endj, vector<vector<int>>& grid, int travelvoid){
        int m=grid.size();
        int n=grid[0].size();    
        if(i==endi && j==endj && cnt==travelvoid-1){
            ans++;
        }
        for(int k=0; k<4; k++){
            int x=dirx[k]+i;
            int y=diry[k]+j;
            if(x<0 || y<0 || x>=m || y>=n || grid[x][y]==-1)continue;
            grid[i][j]=-1;
            solve(x,y,endi,endj,grid,travelvoid+1);
            grid[i][j]=0;
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int sti,stj;
        int endi,endj;
        int travelvoid=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    sti=i;
                    stj=j;
                }
                else if(grid[i][j]==2){
                    endi=i;
                    endj=j;
                }
                else if(grid[i][j]==0){
                    cnt++;
                }

            }
        }
        solve(sti,stj,endi,endj,grid,travelvoid);
        return ans;
    }
};