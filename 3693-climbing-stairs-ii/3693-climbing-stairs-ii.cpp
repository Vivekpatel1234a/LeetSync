class Solution {
public:
    int dp[100001];

    int solve(int i, vector<int>& costs) {
        int n = costs.size();
        // Base case
        if (i == 0) return 0;
        if (dp[i] != -1) return dp[i];
        int mini = INT_MAX;
        // Jump 1 stair
        if (i - 1 >= 0) {
            int ans = costs[i-1] + 1 + solve(i - 1, costs);
            mini = min(mini, ans);
        }
        // Jump 2 stairs
        if (i - 2 >= 0) {
            int ans = costs[i-1] + 4 + solve(i - 2, costs);
            mini = min(mini, ans);
        }
        // Jump 3 stairs
        if (i - 3 >= 0) {
            int ans = costs[i-1] + 9 + solve(i - 3, costs);
            mini = min(mini, ans);
        }
        return dp[i] = mini;
    }
    int climbStairs(int n, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
      //  int n=costs.size();
        return solve(n, costs);
    }
};
/*
class Solution {
public:
    int dp[100001];

    int solve(int i, vector<int>& costs) {
        int n = costs.size();
        // Base case
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int mini = INT_MAX;
        // Jump 1 stair
        if (i + 1 <= n) {
            int ans = costs[i] + 1 + solve(i + 1, costs);
            mini = min(mini, ans);
        }
        // Jump 2 stairs
        if (i + 2 <= n) {
            int ans = costs[i + 1] + 4 + solve(i + 2, costs);
            mini = min(mini, ans);
        }
        // Jump 3 stairs
        if (i + 3 <= n) {
            int ans = costs[i + 2] + 9 + solve(i + 3, costs);
            mini = min(mini, ans);
        }
        return dp[i] = mini;
    }
    int climbStairs(int n, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(0, costs);
    }
};*/