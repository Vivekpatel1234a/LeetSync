class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
       vector<vector<int>>visited(m,vector<int>(n,0));
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         visited[i][j]=grid[i][j];
        //     }
        // }
        priority_queue<vector<int>>pq;
        vector<vector<int>>mat{{1,0},{0,1},{-1,0},{0,-1}};
        int h,i,j,i1,j1;
        if(grid[0][0]==1)health--;
        visited[0][0]=health;
        pq.push({health,0,0});
        //visited[0][0]=1;
        while(!pq.empty()){
            //int sz=pq.size();
            //while(sz--){
                auto it=pq.top();
                pq.pop();
                h=it[0];
                i=it[1];
                j=it[2];
                cout<<h<<" "<<i<<" "<<j<<"    ";
                if(i==m-1 && j==n-1)return true;
                for(auto ele:mat){
                   i1=ele[0];
                   j1=ele[1];
                   if(i+i1<m && i+i1>=0 && j+j1<n && j+j1>=0){
                    //visited[i+i1][j+j1]=1;
                    int nh=h;
                    if(grid[i+i1][j+j1]==1) nh--;
                    if(nh>visited[i+i1][j+j1]){
                        visited[i+i1][j+j1]=nh;
                        pq.push({nh,i+i1,j+j1});
                    }
                   }
                //}  
             
            }
        }
        return false;
    }
};