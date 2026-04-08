class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        int minutes = 0;

        while(!q.empty() && fresh > 0){
            int size = q.size();

            for(int i=0;i<size;i++){
                int mx = q.front().first;
                int my = q.front().second;
                q.pop();

                for(int k=0;k<4;k++){
                    int nx = mx + dx[k];
                    int ny = my + dy[k];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        fresh--;
                    }
                }
            }

            minutes++;
        }

        if(fresh > 0) return -1;
        return minutes;
    }
};