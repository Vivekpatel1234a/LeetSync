/*//solve it from 0 to n bcz its n to 0
class Solution {
public:
    int dp[101];
    int solve(int i,vector<int>&nums){
        if(i<0)return 0;
        if(i==0)return nums[i];
        if(dp[i]!=-1)return dp[i];
        int pick=nums[i]+solve(i-2,nums);
        int nopick=solve(i-1,nums);
        cout<<pick<<" "<<nopick<<"   ";
        return dp[i]=max(pick,nopick);
    }

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int i=n-1;
        int ans=solve(i,nums);
        return ans;
    }
};*/
class Solution {
public:
    int dp[101];

   int solve(int i, vector<int>&nums){
    if(i>=nums.size())return 0;
    if(dp[i]!=-1)return dp[i];
    //if(i==nums.size()-1)return nums[i];
    return dp[i]=max(solve(i+2,nums)+nums[i],solve(i+1,nums));
   }

    int rob(vector<int>& nums){
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,nums);
        return ans;

    }
};