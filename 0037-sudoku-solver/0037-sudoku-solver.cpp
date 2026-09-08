class Solution {
public:

    bool isvalid(int i, int j, char d, vector<vector<char>>& grid){
        for(int k=0; k<9; k++){
            if(grid[i][k]==d)return false;
            if(grid[k][j]==d)return false;
        }
        int sti=(i/3)*3;
        int stj=(j/3)*3;
        for(int l=0; l<3; l++){
            for(int k=0; k<3; k++){
                if(grid[l+sti][k+stj]==d)return false;
            }
        }
        return true;
    }

    bool solveSudoku(vector<vector<char>>& grid){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(grid[i][j]=='.'){
                    for(char k='1'; k<='9'; k++){
                        if(isvalid(i,j,k,grid)){
                            grid[i][j]=k;
                            if(solveSudoku(grid)){
                                return true;
                            }
                            grid[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};