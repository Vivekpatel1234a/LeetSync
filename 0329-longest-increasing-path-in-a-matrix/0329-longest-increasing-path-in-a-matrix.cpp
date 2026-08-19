class Solution {
public:
    int dp[201][201];
     int dx[4] = {1,-1,0,0};
     int dy[4] = {0,0,-1,1};
    int solve(int i, int j, vector<vector<int>>& matrix,int maxi){
    //  cout<<i<<" "<<j<<"   ";
      int m=matrix.size();
      int n=matrix[0].size();

       int local=maxi;
      for(int k=0; k<4; k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 && x<m && y>=0 && y<n && matrix[x][y]>matrix[i][j]){
            if(dp[x][y]!=-1)local=max(local,1+dp[x][y]);
          else  local=max(local,1+solve(x,y,matrix,maxi));
        }
      }
     // cout<<maxi<<". ";
      return dp[i][j]=local;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int maxi=1;
        int res=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
              //  cout<<"    "<<i<<" "<<j<<"->";
              if(dp[i][j]!=-1)continue;
               int ans= dp[i][j]=solve(i,j,matrix,maxi);
              //  cout<<ans<<"...";
               res=max(res,ans);
            }
        }
        return res;
    }
};