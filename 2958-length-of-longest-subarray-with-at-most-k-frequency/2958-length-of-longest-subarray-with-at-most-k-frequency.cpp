class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int j=0;
        int maxi=0;
        for(int i=0; i<n; i++){
            while(j<n && mp[nums[j]]<k){
                mp[nums[j]]++;
                j++;
            }
            maxi=max(maxi,j-i);
            mp[nums[i]]--;
        }
        return maxi;
    }
};