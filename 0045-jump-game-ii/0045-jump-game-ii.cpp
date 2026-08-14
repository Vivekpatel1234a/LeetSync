class Solution {
public:
    int jump(vector<int>& nums) {
     int n=nums.size();
     if(n==1)return 0;
     nums[n-1]=0;
     for(int i=n-2; i>=0; i--){
        int step=nums[i];
        int mini=INT_MAX;
        if(nums[i]>=(n-1)-i){
            nums[i]=1;
            continue;
        }
        while(step>0 ){
           if(nums[i+step]>=0) mini=min(mini,nums[i+step]);
            step--;
        }
        if(mini==INT_MAX)nums[i]=-1;
        else nums[i]=mini+1;
       
     }
     return nums[0];
    }
};