class Solution {
public:
    
  void  solve(int r,int c, int color,vector<vector<int>>& image,vector<vector<int>>& visited,int m,int n,int init){
        if(visited[r][c])return;
        visited[r][c]=1;
        image[r][c]=color;
        if(r+1<m && image[r+1][c]==init){
            solve(r+1,c,color,image,visited,m,n,init);
        }
        if(c+1<n && image[r][c+1]==init){
            solve(r,c+1,color,image,visited,m,n,init);
        }
        if(r-1>=0 && image[r-1][c]==init){
            solve(r-1,c,color,image,visited,m,n,init);
        }
        if(c-1>=0 && image[r][c-1]==init){
            solve(r,c-1,color,image,visited,m,n,init);
        }
        //up
        //down
        //left
        //right

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     int m=image.size();
     int n=image[0].size();
     vector<vector<int>>vis(m,vector<int>(n,0));
     int init=image[sr][sc];
     solve(sr,sc,color,image,vis,m,n,init);
     return image;  
    }
};