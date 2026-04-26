class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(vis[i][j] == 0) {

                    queue<pair<pair<int,int>, pair<int,int>>> q;

                    q.push({{i, j}, {-1, -1}});
                    vis[i][j] = 1;

                    while(!q.empty()) {
                        auto front = q.front();
                        q.pop();

                        int x = front.first.first;
                        int y = front.first.second;

                        int px = front.second.first;
                        int py = front.second.second;

                        int dx[] = {-1, 0, 1, 0};
                        int dy[] = {0, 1, 0, -1};

                        for(int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if(nx >= 0 && ny >= 0 && nx < n && ny < m 
                               && grid[nx][ny] == grid[x][y]) {

                                if(!vis[nx][ny]) {
                                    vis[nx][ny] = 1;
                                    q.push({{nx, ny}, {x, y}});
                                }
                                else if(!(nx == px && ny == py)) {
                                    return true;
                                }}}}}}}

              return false;}
    
};