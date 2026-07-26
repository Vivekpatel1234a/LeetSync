class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x1,x2,x3,y1,y2,y3;
        int n=nums.size();
        x1=nums[0];
        x2=nums[1];
        return max(x1*x2*nums[n-1],nums[n-1]*nums[n-2]*nums[n-3]);
    }
};