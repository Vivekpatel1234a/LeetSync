class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        if(nums.size()%2!=0){
            int mid=nums[n/2];
            for(auto ele:nums)ans=ans+abs(ele-mid);
            return ans;
        }
        else{
            int mid=(nums[n/2]+nums[(n/2)-1])/2;
            for(auto ele:nums)ans=ans+abs(ele-mid);
            return ans;
        }
    }
};