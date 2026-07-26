class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       int firstmax=-1001,secmax=-1001,thirdmax=-1001,firstmin=1001,secmin=1001;
       int n=nums.size();
       for(int i=0; i<n; i++){
        if(nums[i]>firstmax){
            thirdmax=secmax;
            secmax=firstmax;
            firstmax=nums[i];
        }
        else if(nums[i]>secmax){
           thirdmax=secmax;
            secmax=nums[i]; 
        }
        else if(nums[i]>thirdmax){
            thirdmax=nums[i];
        }
         if(nums[i]<firstmin){
            secmin=firstmin;
            firstmin=nums[i];
        }
        else if(nums[i]<secmin){
            secmin=nums[i];
        }
       }
        return max(firstmax*secmax*thirdmax,firstmin*secmin*firstmax);
       return 0;
    }
};