class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int i=0;
        long long maxi=0;
        long long sum=0;
        for(int i=0; i<k; i++){
            mp[nums[i]]++;
            sum+=nums[i];
            if(mp.size()==k)maxi=max(maxi,sum);
        }
        int j=k;
        while(j<n){
            int suf=nums[j];
            int pre=nums[j-k];
            sum+=suf;
            sum-=pre;
            mp[suf]++;
            mp[pre]--;
            if(mp[pre]==0)mp.erase(pre);
            j++;
            if(mp.size()==k)maxi=max(maxi,sum);

        }
        return maxi;
    }
};