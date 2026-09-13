class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        int m=n;
        for(int i=0; i<n; i++){
        int k=rowShift[i];
        vector<int>temp(n);
        for(int j=0; j<n; j++){
         int newidx=(j-k+n)%n;
         temp[newidx]=grid[i][j]; 
        }
        for(int j=0; j<n; j++){
            grid[i][j]=temp[j];
        }
        }
        for(int j=0; j<n; j++){
        int k=colShift[j];
        vector<int>temp(n);
        for(int i=0; i<n; i++){
         int newidx=(i-k+n)%n;
         temp[newidx]=grid[i][j]; 
        }
        for(int i=0; i<n; i++){
            grid[i][j]=temp[i];
        }
        }

        return grid;
    }
};