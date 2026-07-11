class Solution {
public:
    void hell(int &vertices, int &degreeSum, vector<int> &vis,
              int node, vector<vector<int>> &adj) {

        vis[node] = 1;
        vertices++;
        degreeSum += adj[node].size();

        for (int nei : adj[node]) {
            if (!vis[nei])
                hell(vertices, degreeSum, vis, nei, adj);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &ed : edges) {
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        vector<int> vis(n, 0);
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int vertices = 0;
                int degreeSum = 0;

                hell(vertices, degreeSum, vis, i, adj);

                int edgeCount = degreeSum / 2;

                if (edgeCount == vertices * (vertices - 1) / 2)
                    res++;
            }
        }

        return res;
    }
};