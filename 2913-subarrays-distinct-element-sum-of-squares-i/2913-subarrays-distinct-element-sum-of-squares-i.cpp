class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            unordered_map<int,int>mp;
            int cnt=0;
            for(int j=i; j<n; j++){
                if(!mp.count(nums[j])){
                    cnt++;
                    mp[nums[j]]++;
                }
               res=res+(cnt*cnt);
            }
        }
        return res;
    }
};