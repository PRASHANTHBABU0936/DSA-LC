class Solution {
public:
vector<vector<int>> memo;
    int dfs(int i, int j, vector<vector<int>>& obstacleGrid, int n, int m) {

        if (i >= n || j >= m)
            return 0;

        if (obstacleGrid[i][j] == 1)
            return 0;
if(memo[i][j] != -1) return memo[i][j];
        if (i == n - 1 && j == m - 1)
            return 1;

        return memo[i][j]=dfs(i + 1, j, obstacleGrid, n, m) +
               dfs(i, j + 1, obstacleGrid, n, m);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
memo.assign(n,vector<int>(m,-1));
        return dfs(0, 0, obstacleGrid, n, m);
    }
};