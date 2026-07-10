class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int mini=nums[0];
        int ans=abs(nums[0]);
        for(int i=1; i<n; i++){
            maxi=max(nums[i],maxi+nums[i]);
            mini=min(nums[i],mini+nums[i]);
            ans=max({ans,maxi,abs(mini)});
        }
        return ans;
    }
};