class Solution {
public:

//optimise it

    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>oR(m,0);
        vector<int>oC(n,0);
        // for(int i=0; i<m; i++){
        //  for(int j=0; j<n; j++){
        //     oR[i]+=grid[i][j];
        //  }
        // }
        // for(int j=0; j<n; j++){
        //  for(int i=0; i<m; i++){
        //     oC[j]+=grid[i][j];
        //  }
        // }
        //combine them to one and its also correct 
        for(int j=0; j<n; j++){
         for(int i=0; i<m; i++){
            oC[j]+=grid[i][j];
            oR[i]+=grid[i][j];
         }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                grid[i][j]=oR[i]+oC[j]-(m-oR[i]+n-oC[j]);
            }
            
        }
    return grid;
    }
};