class Solution {
public:
    int dp[101][101];

    int solve(int i, int j, int m, int n){
        if(i >= m) return 0;
        if(j >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(i == m-1 && j == n-1) return 1;

        return dp[i][j] = solve(i+1, j, m, n) + solve(i, j+1, m, n);
    }

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));

        int ans = solve(0, 0, m, n);
        return ans;
    }
};