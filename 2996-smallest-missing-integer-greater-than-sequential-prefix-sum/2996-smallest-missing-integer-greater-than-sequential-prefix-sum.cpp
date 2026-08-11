class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int i=1;
        while(i<n && nums[i]==nums[i-1]+1){
            sum+=nums[i];
            i++;
        }
        unordered_map<int,int>mp;
        for(int j=i-1; j<n; j++){
            mp[nums[j]]++;
        }
        int temp=sum;
        while(true){
            if(mp.count(temp)){
            }
            else {
                break;
            }
            temp++;
        }
        return temp;
        
    }
};