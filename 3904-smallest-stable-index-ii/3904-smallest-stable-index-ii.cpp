class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>mini(n);
        int m=INT_MAX;
        for(int i=n-1; i>=0; i--){
        m=min(m,nums[i]);
        mini[i]=m;
       }
       int pre=INT_MIN;
       for(int i=0; i<n; i++){
        pre=max(pre,nums[i]);
        if((pre-mini[i])<=k){return i;
       }
       }
       return -1;   
    }
};