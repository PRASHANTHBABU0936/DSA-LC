class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        int layers = min(m, n) / 2;
        
        for(int l = 0; l < layers; l++) {
            vector<int> temp;
            
            for(int j = l; j < n - l; j++)
                temp.push_back(grid[l][j]);
            
            for(int i = l + 1; i < m - l - 1; i++)
                temp.push_back(grid[i][n - l - 1]);
            
            for(int j = n - l - 1; j >= l; j--)
                temp.push_back(grid[m - l - 1][j]);
            
            for(int i = m - l - 2; i > l; i--)
                temp.push_back(grid[i][l]);
            
            int len = temp.size();
            int rot = k % len;
            
            vector<int> rotated(len);
            for(int i = 0; i < len; i++)
                rotated[i] = temp[(i + rot) % len];
            
            int idx = 0;
            
            for(int j = l; j < n - l; j++)
                grid[l][j] = rotated[idx++];
            
            for(int i = l + 1; i < m - l - 1; i++)
                grid[i][n - l - 1] = rotated[idx++];
            
            for(int j = n - l - 1; j >= l; j--)
                grid[m - l - 1][j] = rotated[idx++];
            
            for(int i = m - l - 2; i > l; i--)
                grid[i][l] = rotated[idx++];
        }
        
        return grid;
    }
};