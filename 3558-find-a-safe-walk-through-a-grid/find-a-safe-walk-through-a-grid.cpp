class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            less<tuple<int,int,int>>
        > pq;

        vector<vector<int>> vis(n, vector<int>(m, -1));

        int startHealth = health - grid[0][0];
        if (startHealth < 1)
            return false;

        pq.push({startHealth, 0, 0});
        vis[0][0] = startHealth;

        while (!pq.empty()) {

            int hell1 = get<0>(pq.top()); // remaining health
            int hell2 = get<1>(pq.top()); // row
            int hell3 = get<2>(pq.top()); // col
            pq.pop();

            if (hell2 == n - 1 && hell3 == m - 1)
                return true;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {

                int nr = hell2 + dx[i];
                int nc = hell3 + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {

                    int newHealth = hell1 - grid[nr][nc];

                    if (newHealth >= 1 && newHealth > vis[nr][nc]) {
                        vis[nr][nc] = newHealth;
                        pq.push({newHealth, nr, nc});
                    }
                }
            }
        }

        return false;
    }
};