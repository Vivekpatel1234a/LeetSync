class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {//height->grid
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
        maxi=max(maxi,nodecost);//bcz 
        if(i==m-1 && j==n-1){
            return maxi;
        }
        for(auto ele:vec){
            int i1=ele.first;
            int j1=ele.second;
            if(i1+i<m && j1+j<n && i1+i>=0 && j1+j>=0 && !vis[i1+i][j1+j]){
            pq.push({abs(grid[i1+i][j1+j]-grid[i][j]),{i1+i,j1+j}}); 

            }
        }
     }
     return maxi;   
    }
};