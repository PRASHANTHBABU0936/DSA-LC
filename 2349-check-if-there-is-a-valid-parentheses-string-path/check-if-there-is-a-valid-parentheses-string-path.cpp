class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int len = m + n - 1;

        // Odd length can never form a valid parentheses string
        if (len % 2)
            return false;

        // dp[i][j][balance]
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(len + 1, false))
        );

        // Starting cell must be '('
        if (grid[0][0] == ')')
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int balance = 0; balance <= len; balance++) {

                    if (!dp[i][j][balance])
                        continue;

                    // Move down
                    if (i + 1 < m) {
                        int newBalance =
                            balance + (grid[i + 1][j] == '(' ? 1 : -1);

                        if (newBalance >= 0)
                            dp[i + 1][j][newBalance] = true;
                    }

                    // Move right
                    if (j + 1 < n) {
                        int newBalance =
                            balance + (grid[i][j + 1] == '(' ? 1 : -1);

                        if (newBalance >= 0)
                            dp[i][j + 1][newBalance] = true;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};