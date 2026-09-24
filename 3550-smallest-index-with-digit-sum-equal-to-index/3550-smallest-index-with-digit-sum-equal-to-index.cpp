class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            int n=nums[i];
            int sum=0;
            while(n>0){
                sum=sum+n%10;
                n=n/10;
            }
            if(sum==i) ans.push_back(i);
        }
        if(ans.size()==0) return -1;
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};