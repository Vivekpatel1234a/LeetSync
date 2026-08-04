class Solution {
public:

    int solve(int i, int j, vector<int>&nums){
        if(i>j)return 0;
        int ans=max(nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums)),nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums)));
        
        return ans;

    }

    bool predictTheWinner(vector<int>& nums) {
      int n=nums.size();
      int sum=0;
      for(auto ele:nums)sum+=ele;
      int i=0;
      int j=n-1;
      int ans=max(nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums)),nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums)));
     
      return ans>=sum-ans;
    }
};