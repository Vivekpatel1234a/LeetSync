class Solution {
public:
    vector<vector<int>>dp;
    int dirx[3]={1,1,1};
    int diry[3]={-1,0,1};
    int solve(int i, int j, int m, int n,vector<vector<int>>& matrix){
        if(dp[i][j]!=1e5){
            return dp[i][j];
        }
      //  cout<<i<<" "<<j<<"   ";
        if(i==m-1)return matrix[i][j];
        int mini=1e9;
        for(int k=0; k<3; k++){
            int x=i+dirx[k];
            int y=j+diry[k];
           if(x>=0 && y>=0 && x<m && y<n ){
            if(dp[x][y]!=1e5){
                mini=min(mini,dp[x][y]+matrix[i][j]);
            }
            else mini=min(mini,solve(x,y,m,n,matrix)+matrix[i][j]);
           }
        }
        return dp[i][j]=mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
       
        int m=matrix.size();
        int n=matrix[0].size();
        dp.assign(m, vector<int>(n, 1e5));
        int minians=1e5;
        for(int j=0; j<n; j++){
        int ans=solve(0,j,m,n,matrix);
        minians=min(minians,ans);
        }
        return minians;
    }
};