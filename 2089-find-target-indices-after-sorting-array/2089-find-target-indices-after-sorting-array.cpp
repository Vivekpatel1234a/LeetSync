class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less=0;
        int grt=0;
        int n=nums.size();
        for(auto ele:nums){
            if(ele<target)less++;
            else if(ele>target)grt++;
        }
        int st=less;
        vector<int>ans;
        for(int i=0; i<(n-(grt+less)); i++)ans.push_back(st+i);
        return ans;
    }
};