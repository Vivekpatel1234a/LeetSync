class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=-1;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            int rem=sum%k;
            //if(rem<0)rem+=k; bcz there is no -ve numbers 
            if(mp.count(rem)){
                if(i-mp[rem]>=2)return true;
            }
            else mp[rem]=i;
        }
        return false;
    }
};