class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
       unordered_map<int,int>mp2;
        int n=nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            int j=i-k;
            if(j>=0)mp[nums[j]]--;
           if(j>=0)if(mp[nums[j]]==0)mp.erase(nums[j]);
            if(i-k+1>=0){
                for(auto& ele:mp){
                    mp2[ele.first]++;
                }
            }
             
        }
        int maxi=-1;
        for(auto& ele:mp2){
            if(ele.second==1){
                maxi=max(maxi,ele.first);
            }
        }
        return maxi;
    }
};