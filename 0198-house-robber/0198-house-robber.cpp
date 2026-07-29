class Solution {
public:
    int dp[101];
    int solve(int i,vector<int>&nums){
        if(i<0)return 0;
        if(i==0)return nums[i];
        if(dp[i]!=-1)return dp[i];
        int pick=nums[i]+solve(i-2,nums);
        int nopick=solve(i-1,nums);
        return dp[i]=max(pick,nopick);
    }

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int i=n-1;
        int ans=solve(i,nums);
        return ans;
    }
};