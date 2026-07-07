class NumMatrix {
public:
    vector<vector<int>>pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        pre.resize(m, vector<int>(n));
        pre[0][0]=matrix[0][0];
        
        for(int j=1; j<n; j++){
            pre[0][j]=pre[0][j-1]+matrix[0][j];
            //cout<<pre[0][j]<<" ";
        }
        for(int j=1; j<m; j++){
            pre[j][0]=pre[j-1][0]+matrix[j][0];
            //cout<<pre[j][0]<<" ";
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                pre[i][j]=matrix[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
               // cout<<pre[i][j]<<" ";
            }
            //cout<<endl;
        }
        
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans1=pre[row2][col2];
        int ans2=0,ans3=0,ans4=0;
        if(row1-1>=0){
            ans2=pre[row1-1][col2];
        }
        if(col1-1>=0)ans3=pre[row2][col1-1];

        if(row1-1>=0 && col1-1>=0)ans4=pre[row1-1][col1-1];
        //else if(row1-1>=0)ans4=pre[row1-1][col1];
        //else if(col1-1>=0)ans4=pre[row1][col1-1];
       // cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4;
      //  cout<<endl;
        return ans1-ans2-ans3+ans4;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */