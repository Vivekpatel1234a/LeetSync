class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle,vector<vector<int>>& dp){
        int m=triangle.size();
        if(i==m)return 0;
        if(dp[i][j]!=INT_MIN)return dp[i][j];
        int left=triangle[i][j]+solve(i+1,j,triangle,dp);
        int right=triangle[i][j]+solve(i+1,j+1,triangle,dp);
        return dp[i][j]=min(left,right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m=triangle.size();
       // int n=triangle[0].size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,INT_MIN));
        int i=0;
        int j=0;
        int ans=solve(i,j,triangle,dp);
        return ans;
    }
};