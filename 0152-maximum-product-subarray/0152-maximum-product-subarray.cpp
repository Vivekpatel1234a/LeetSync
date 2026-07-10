/*
At every index, the maximum product ending here can come from either starting fresh, extending the previous maximum, or extending the previous minimum (because multiplying by a negative flips signs).
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int currsum=nums[0];
        int maxi=nums[0];
        int mini=nums[0];
        int ans=nums[0];
        for(int i=1; i<n; i++){
            int val=nums[i];
            int pmaxi=maxi;
            int pmini=mini;
            maxi=max({val,pmini*nums[i],pmaxi*nums[i]});//
            mini=min({val,pmaxi*nums[i],pmini*nums[i]});
            ans=max(maxi,ans);
        }
        return ans;
    }
};