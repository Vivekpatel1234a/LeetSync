class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fresh=1;
            }
        }
        if(q.size()==0 && fresh==0)return 0;
        int time=0;
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int sz=q.size();
            time++;
            for(int k=0; k<sz; k++){
                auto it=q.front();
                q.pop();
                int i=it.first;
                int j=it.second;
                for(auto pr:dir){
                    int x=pr.first+i;
                    int y=pr.second+j;
                    if(x<m && y<n && x>=0 && y>=0 && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                    
                }

            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return  time-1;
    }
};