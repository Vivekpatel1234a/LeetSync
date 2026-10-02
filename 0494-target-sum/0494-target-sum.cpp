class Solution {
public:
    int solve(vector<int>& nums, int sum, int n) {
        if(n == 0)
            return sum == 0;

        if(nums[n-1] <= sum)
            return solve(nums, sum - nums[n-1], n-1)
                 + solve(nums, sum, n-1);

        return solve(nums, sum, n-1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int S = accumulate(nums.begin(), nums.end(), 0);

        if(S + target < 0 || (S + target) % 2 != 0)
            return 0;

        int sum = (S + target) / 2;

        return solve(nums, sum, nums.size());
    }
};