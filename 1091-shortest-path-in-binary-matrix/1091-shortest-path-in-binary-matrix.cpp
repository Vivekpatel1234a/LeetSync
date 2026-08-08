class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>>q;
        if(grid[0][0]==1)return -1;
        q.push({0,0,1});
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        visited[0][0]=1;
          vector<pair<int,int>>pr{{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        while(!q.empty()){
            auto [i,j,cost]=q.front();
            q.pop();
           /* int i=it[0];
            int j=it[1];
            int cost=it[2];*/
            if(i==m-1 && j==n-1)return cost;
            //if(visited[i][j])continue;
            //visited[i][j]=1;
            for(auto& p:pr){
                auto& x=p.first;
                auto& y=p.second;
                int i1=i+x;
                int j1=j+y;
                if(i1>=m || i1<0 || j1>=n || j1<0 || grid[i1][j1]==1)continue;
                else{
                    if(!visited[i1][j1]){
                        visited[i1][j1]=1;
                    q.push({i1,j1,cost+1});
                    }
                }
            }
        }
        return -1;
    }
};