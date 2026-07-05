class Solution {
public:

    // Recursive DFS
    bool hell(vector<vector<char>>& board, string word,
              int index1, int index2,
              string t, int c,
              int n, int m,
              vector<vector<bool>>& vis)
    {
        // Out of bounds
        if(index1 < 0 || index1 >= n || index2 < 0 || index2 >= m)
            return false;

        // Already visited
        if(vis[index1][index2])
            return false;

        // Character does not match
        if(board[index1][index2] != word[c])
            return false;

        // Include current character
        t += board[index1][index2];

        // Entire word formed
        if(t == word)
            return true;

        // Mark current cell as visited
        vis[index1][index2] = true;

        // 4 possible directions
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++)
        {
            if(hell(board, word,
                    index1 + dx[i],
                    index2 + dy[i],
                    t,
                    c + 1,
                    n,
                    m,
                    vis))
                return true;
        }

        // Backtracking
        vis[index1][index2] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        // Try every cell as starting point
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<bool>> vis(n, vector<bool>(m, false));

                    // Start matching from first character (c = 0)
                    if(hell(board, word, i, j, "", 0, n, m, vis))
                        return true;
                }
            }
        }

        return false;
    }
};