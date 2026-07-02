class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>mat{{1,0},{0,1},{-1,0},{0,-1}};
        deque<tuple<int,int>>dq;
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        dq.push_front({0,0});
        result[0][0]=grid[0][0];
        while(!dq.empty()){
            auto it=dq.front();
            dq.pop_front();
            auto[i,j]=it;
            for(auto ele:mat){
                int nr=ele[0]+i;
                int nc=ele[1]+j;
                if(nr<0 ||nr>=m || nc<0 ||nc>=n)continue;
                if(result[nr][nc]>result[i][j]+grid[nr][nc]){
                    result[nr][nc]=result[i][j]+grid[nr][nc];
                    if(grid[nr][nc]==0)dq.push_front({nr,nc});
                    if(grid[nr][nc]==1)dq.push_back({nr,nc});
                }
                
            }
        }
        int x=result[m-1][n-1];
        return health-x>=1;
    }
};