class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int minidx=0;
        int maxidx=0;
        for(int i=0; i<n; i++){
            if(nums[i]<mini){
                mini=nums[i];
                minidx=i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                maxidx=i;
            }
        }
        cout<<minidx<<" "<<maxidx;
        int left=max(minidx,maxidx)+1;
        int right=max(n-maxidx,n-minidx);
        int opp1=((maxidx+1)+n-minidx);
        int opp2=((minidx+1)+n-maxidx);
        return min({left,right,opp1,opp2});
    }
};