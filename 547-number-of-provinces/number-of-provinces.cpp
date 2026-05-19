class Solution {
public:
    void bfs(int j, vector<int> &vis, vector<vector<int>>& isConnected, int n){
        vis[j] = 1;

        for(int k = 0; k < n; k++){
            if(isConnected[j][k] == 1 && vis[k] == 0){
                bfs(k, vis, isConnected, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                count++;
                bfs(i, vis, isConnected, n);
            }
        }
        return count;
    }
};