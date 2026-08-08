class Solution {
public:
    int m,n;
    void solve(int i, int j,vector<vector<char>>& board, vector<vector<int>>& visited){
    if(i<0 || j<0 || i>=m || j>=n || visited[i][j] || board[i][j]=='X'){
        return;
    }
    visited[i][j]=1;
    board[i][j]='.';
    solve(i+1,j,board,visited);
    solve(i,j+1,board,visited);
    solve(i-1,j,board,visited);
    solve(i,j-1,board,visited);
    }

    void solve(vector<vector<char>>& board) {
       m=board.size();
       n=board[0].size();
      vector<vector<int>>visited(m,vector<int>(n,0));
      int i,j;
      for( i=0; i<m; i++){
        j=0;
        solve(i,j,board,visited);
        j=n-1;
        solve(i,j,board,visited);
        }
        for(j=0; j<n; j++){
        i=0;
        solve(i,j,board,visited);
        i=m-1;
            solve(i,j,board,visited);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='.')board[i][j]='O';
                else board[i][j]='X';
            }
        }
      return;
    }
};