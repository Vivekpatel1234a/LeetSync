class Solution {
    //iswater to mat same as 0 1 graph
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int m=mat.size();
        int n=mat[0].size();
        //here 1 means water and 0 means land and if its water then height is 0, jaise ke diya hai absolute diff must have 1 to vo multisource bfs se aa jayega draw diagram
        vector<vector<int>>ans(m,vector<int>(n,-1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1){//if water then it must be 0
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