class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int i=it.first;
            int j=it.second;
            if(i+1<m && ans[i+1][j]==-1){
                ans[i+1][j]=1+ans[i][j];
                q.push({i+1,j}); 
            }
            if(j+1<n && ans[i][j+1]==-1){
                ans[i][j+1]=1+ans[i][j];
                q.push({i,j+1});    
            }
            if(i-1>=0 && ans[i-1][j]==-1){
                ans[i-1][j]=1+ans[i][j]; 
                q.push({i-1,j});   
            }
            if(j-1>=0 && ans[i][j-1]==-1){
                ans[i][j-1]=1+ans[i][j]; 
                q.push({i,j-1});   
            }
        }
        return ans;
    }
};