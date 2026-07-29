class Solution {
public:
    int dp[101];
    int solve(int i,int st,vector<int>&nums){
        if(i<st)return 0;
        if(i==st)return nums[i];
        if(dp[i]!=-1)return dp[i];
        int pick=nums[i]+solve(i-2,st,nums);
        int nopick=solve(i-1,st,nums);
        return dp[i]=max(pick,nopick);
    }

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        if(n==1)return nums[0];
        int st=0;
        int ans=solve(n-1,st+1,nums);
        st=0;
        memset(dp,-1,sizeof(dp));
        int ans2=solve(n-2,st,nums);
        return max(ans,ans2);
    }
};