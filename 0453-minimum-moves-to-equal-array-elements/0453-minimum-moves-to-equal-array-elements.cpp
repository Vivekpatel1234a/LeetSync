class Solution {
public:
    int minMoves(vector<int>& nums) {
       int sum=0;
       int cmn=*min_element(nums.begin(),nums.end());
       for(auto ele:nums){
        sum+=ele-cmn;
       }
       return sum;
    }
};