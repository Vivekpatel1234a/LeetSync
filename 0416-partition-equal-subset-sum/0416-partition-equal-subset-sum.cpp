/*class Solution {
public:
    int sum=0;
    vector<vector<int>>dp;
    int solve(int idx,int cnt,vector<int>&nums){
        if(dp[idx][cnt]!=-1)return dp[idx][cnt];
        if(cnt==(sum-cnt))return 1;
        if(idx>=nums.size() || cnt>sum-cnt)return 0;
        if(nums[idx]<=sum/2){
           return dp[idx][cnt]=((solve(idx+1,cnt+nums[idx],nums))||(solve(idx+1,cnt,nums)));
        }
       return dp[idx][cnt]=0;
    }

    bool canPartition(vector<int>& nums) {
        //memset(dp,-1,sizeof(dp));
        int n=nums.size();
        for(auto ele:nums)sum+=ele;
        if(sum%2!=0)return 0;
        dp.resize(201);
        for(auto& it:dp)it.resize(sum,-1);
        int cnt=0;
        return solve(0,cnt,nums);

    }
};*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto ele:nums)sum+=ele;
        if(sum%2!=0)return 0; 
        sum=sum/2;
        int dp[n+1][sum+1];
        for(int i=0; i<=n; i++)dp[i][0]=1;
        for(int j=0; j<=sum; j++)dp[0][j]=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
               if(nums[i-1]<=j)dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
               else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
 }
};