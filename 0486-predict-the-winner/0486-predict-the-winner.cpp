class Solution {
public:
    int dp[21][21];
    int solve(int i, int j, vector<int>&nums){
        
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=dp[i][j]=max(nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums)),nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums)));
        
        return ans;

    }

    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
      int n=nums.size();
      int sum=0;
      for(auto ele:nums)sum+=ele;
      int i=0;
      int j=n-1;
      int ans=max(nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums)),nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums)));
     
      return ans>=sum-ans;
    }
};