class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
      long long n=nums.size();
        for(long long i=0; i<n; i++){
            if(nums[i]<0){
                nums[i]=-1*nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        for(long long i=0; i<n; i++){
            cout<<nums[i]<<" ";
        }
        long long min=0;
        long long pls=0;
       
           for(long long i=0; i<n/2; i++){
              min=min+(nums[i]*nums[i]); 
           }
            for(long long i=n/2; i<n; i++){
                pls=pls+(nums[i]*nums[i]);
            }
        
       
        return pls-min;
    }
};