class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second.size()==3){
                auto vec=it.second;
                if(vec[1]-vec[0]==vec[2]-vec[1])cnt++;
            }
        }
        return cnt;
    }
};