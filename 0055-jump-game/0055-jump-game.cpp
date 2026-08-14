class Solution {
public:
    bool canJump(vector<int>& nums) {
     int n=nums.size();
     if(n==1)return true;
     int mini=n-1;
     for(int i=n-2; i>=0; i--){
        if(mini-i<=nums[i]){
            mini=i;
        }
     }
     return mini==0;
    }
};