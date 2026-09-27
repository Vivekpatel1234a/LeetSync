class Solution {
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
};