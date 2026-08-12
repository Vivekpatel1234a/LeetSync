class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
      int m=grid.size();
      int n=grid[0].size();
      vector<vector<int>>vis(m,vector<int>(n,0));  
     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
     pq.push({0,{0,0}});
     int maxi=0;
     vector<pair<int,int>>vec={{1,0},{0,1},{-1,0},{0,-1}};
     while(!pq.empty()){
        auto pr=pq.top();
        pq.pop();
        int nodecost=pr.first;
        int i=pr.second.first;
        int j=pr.second.second;
        vis[i][j]=1;
       // cout<<grid[i][j]<<" ";
        maxi=max(maxi,grid[i][j]);
        if(i==m-1 && j==n-1)break;
        for(auto ele:vec){
            int i1=ele.first;
            int j1=ele.second;
            if(i1+i<m && j1+j<n && i1+i>=0 && j1+j>=0 && !vis[i1+i][j1+j]){
            pq.push({grid[i1+i][j1+j],{i1+i,j1+j}});    
            }
        }
     }
     return maxi;
    }
};