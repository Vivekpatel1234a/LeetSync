class Solution {
public:
   bool flag=false;
   int dirx[4]={0,0,1,-1};
   int diry[4]={1,-1,0,0};
   int solve(int idx, int i, int j, vector<vector<char>>& board,string& word,vector<vector<int>>& visited){
    int m=board.size();
    int n=board[0].size();
    visited[i][j]=1;
    if(idx==word.size()){
        flag=true;
        return 1;
    }
    for(int k=0; k<4; k++){
        int i1=i+dirx[k];
        int j1=j+diry[k];
        if(i1>=0 && j1>=0 && i1<m && j1<n && board[i1][j1]==word[idx] && !visited[i1][j1]){
            if(solve(idx+1,i1,j1,board,word,visited)) return 1;
        }
    }
    visited[i][j]=0;
    return 0;
   }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                   if(solve(1,i,j,board,word,visited))return 1;
                }
            }
        }
        return 0;
    }
};