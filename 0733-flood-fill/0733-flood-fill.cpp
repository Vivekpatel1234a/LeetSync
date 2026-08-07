class Solution {
public:
    int old=0;
  void  solve(int r,int c, int color,vector<vector<int>>& image,int m,int n){
        
        if(r>=m || c>=n || r<0 || c<0)return;
        if(image[r][c]!=old)return;
        image[r][c]=color;
            solve(r+1,c,color,image,m,n);
            solve(r,c+1,color,image,m,n);
            solve(r-1,c,color,image,m,n);
            solve(r,c-1,color,image,m,n);
        //up
        //down
        //left
        //right

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     int m=image.size();
     int n=image[0].size();
     old=image[sr][sc];
     if(old==color)return image;
     solve(sr,sc,color,image,m,n);
     return image;  
    }
};