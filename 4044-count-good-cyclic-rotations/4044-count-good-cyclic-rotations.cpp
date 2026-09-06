class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long sum1=0;
        long sum2=0;
        for(int i=0; i<n; i++){
            if(i<n/2)sum1+=nums[i];
            else sum2+=nums[i];
        }
        int cnt=0;
        int cnt2=0;
        int k=n/2;
        for(int i=0; i<k; i++){
            if(sum1>sum2)cnt++;
            else if(sum2>sum1)cnt2++;
            sum1-=nums[i];
            sum1+=nums[i+k];
            sum2+=nums[i];
            sum2-=nums[i+k];
            
        }
        return cnt+cnt2;
    }
};