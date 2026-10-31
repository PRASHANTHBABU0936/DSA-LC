class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        // f[i][j][d]: landing cell (encoded as x*n+y) when trying to enter (i,j) moving d
        // d = 0: right, d = 1: down; -1 means out of bounds
        vector<vector<array<int, 2>>> f(m + 1, vector<array<int, 2>>(n + 1, {-1, -1}));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int d = 0; d < 2; d++) {
                    if (grid[i][j] == 0) {
                        f[i][j][d] = i * n + j;
                    } else if (d == 0) {
                        f[i][j][d] = (i + 1 < m) ? f[i + 1][j][1] : -1;
                    } else {
                        f[i][j][d] = (j + 1 < n) ? f[i][j + 1][0] : -1;
                    }
                }
            }
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0) continue;
                // move right
                if (j + 1 < n) {
                    int t = f[i][j + 1][0];
                    if (t != -1) {
                        int x = t / n, y = t % n;
                        dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                    }
                }
                // move down
                if (i + 1 < m) {
                    int t = f[i + 1][j][1];
                    if (t != -1) {
                        int x = t / n, y = t % n;
                        dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};