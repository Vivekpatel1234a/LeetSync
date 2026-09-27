class Solution {
public:
    int sum=0;
    int dp[201][100000];
    int solve(int idx,int cnt,vector<int>&nums){
        if(dp[idx][cnt]!=-1)return dp[idx][cnt];
        if(cnt==(sum-cnt))return 1;
        if(idx>=nums.size() || cnt>sum-cnt)return 0;
        if(nums[idx]<=sum/2){
           if(solve(idx+1,cnt+nums[idx],nums))return dp[idx][cnt]=1;
           else if(solve(idx+1,cnt,nums))return dp[idx][cnt]=1;
        }
       return dp[idx][cnt]=0;

    }

    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        if(sum%2!=0)return 0;
        for(auto ele:nums)sum+=ele;
        int cnt=0;
        return solve(0,cnt,nums);

    }
};