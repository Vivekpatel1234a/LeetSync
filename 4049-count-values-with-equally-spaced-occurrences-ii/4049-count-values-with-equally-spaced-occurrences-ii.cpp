class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
                unordered_map<int,vector<int>>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        int cnt=0;
        for(auto& it:mp){
            if(it.second.size()>=3){
                auto vec=it.second;
                bool flag=true;
                int diff=vec[1]-vec[0];
                for(int i=2; i<vec.size(); i++){
                    if(vec[i]-vec[i-1]!=diff){
                        flag=false;
                        break;
                    }
                }
                if(flag)cnt++;
            }
        }
        return cnt;
    }
};