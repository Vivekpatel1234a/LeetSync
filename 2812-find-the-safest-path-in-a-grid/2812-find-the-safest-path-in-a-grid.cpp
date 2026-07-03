/*
Approach:
1. Multi-source BFS to compute the minimum distance of every cell from the nearest thief.
2. Binary search on the maximum possible safeness factor.
3. BFS to check if a path exists using only cells with safeness >= mid.

TC: O(n² log n)
SC: O(n²)
*/
class Solution {
public:

    bool solve(vector<vector<int>>& grid, int safe,vector<vector<int>>& mat, vector<vector<int>>& vis, int timer){
        int n=grid.size();
       queue<pair<int,int>>q;
       if(grid[0][0] < safe || grid[n-1][n-1] < safe)return false;
       q.push({0,0});
       vis[0][0]=timer;
       while(!q.empty()){
        auto it=q.front();
        q.pop();
        int i=it.first;
        int j=it.second;
        if(i==n-1 && j==n-1)return true;
        for(auto &ele:mat){
            int i1=ele[0];
            int j1=ele[1];
            int newr=i+i1;
            int newc=j+j1;
            if(newr<0 ||newr>=n || newc<0 || newc>=n || vis[newr][newc]==timer || grid[newr][newc]<safe)continue;
            vis[newr][newc]=timer;
            q.push({newr,newc});
        }
       }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int high=0;
        queue<pair<int,int>>q;
        vector<vector<int>>visited(m,vector<int>(n,0));
        vector<vector<int>>mat={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }  
        }
        int level=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            auto[i,j]=q.front();
            q.pop();
            for(auto &ele:mat){
                int i1=ele[0];
                int j1=ele[1];
                int newr=i+i1;
                int newc=j+j1;
                if(newr<0 ||newr>=m || newc<0 || newc>=n || visited[newr][newc])continue;
                q.push({newr,newc});
                grid[newr][newc]=level;
                visited[newr][newc]=1;
            }
            }
        level++;
        }
        high=level-1;
        int low=0;
        int ans=0;
       vector<vector<int>>vis(m,vector<int>(n,0));
       int timer=0;
        while(low<=high){
             timer++;
            int mid=(low+high)/2;
            if(solve(grid,mid,mat,vis,timer)==1){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }    
    return ans;
    }
};