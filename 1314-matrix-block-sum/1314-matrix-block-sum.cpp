class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> pre(m, vector<int>(n, 0));
        pre[0][0] = matrix[0][0];
        for (int j = 1; j < n; j++)
            pre[0][j] = pre[0][j - 1] + matrix[0][j];
        for (int j = 1; j < m; j++)
            pre[j][0] = pre[j - 1][0] + matrix[j][0];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                pre[i][j] = matrix[i][j] + pre[i - 1][j] + pre[i][j - 1] -
                            pre[i - 1][j - 1];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int ans = 0;
                int maxrow = min(m - 1, i + k);
                int maxcol = min(n - 1, j + k);
                int minrow = max(i - k, 0);
                int mincol = max(j - k, 0);
                ans = pre[maxrow][maxcol];

                if (minrow > 0) //topright
                    ans -= pre[minrow - 1][maxcol];

                if (mincol > 0)//bottom left
                    ans -= pre[maxrow][mincol - 1];

                if (minrow > 0 && mincol > 0) //top left to add bcz removed 2 times
                    ans += pre[minrow - 1][mincol - 1];
                matrix[i][j] = ans;
            }
        }
        return matrix;
    }
};