class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max=*max_element(nums.begin(),nums.end());
        int diff=0;
        for(int i=0; i<nums.size(); i++){
           if(nums[i]<max){
               diff=diff+max-nums[i];
           }
        }

        
        return diff;
    }
};