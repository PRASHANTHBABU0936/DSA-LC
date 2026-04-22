class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, 
             vector<int>& vis, vector<int>& pathVis) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (auto &nbr : adj[node]) {

            // if not visited → go deeper
            if (!vis[nbr]) {
                if (dfs(nbr, adj, vis, pathVis))
                    return true;
            }
            // if already in current path → cycle
            else if (pathVis[nbr]) {
                return true;
            }
        }

        // backtrack
        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for (auto &at : prerequisites) {
            adj[at[1]].push_back(at[0]);
        }

        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis))
                    return false;
            }
        }

        return true;
    }
};