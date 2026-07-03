class Solution {
public:
    bool check(int mid,
               vector<vector<pair<int,int>>> &adj,
               vector<int> &topo,
               vector<bool> &online,
               long long k,
               int n) {

        const long long INF = 1e18;
        vector<long long> dp(n, INF);
        dp[0] = 0;

        for (int u : topo) {
            if (dp[u] == INF) continue;

            for (auto &[v, w] : adj[u]) {

                // Ignore edges with weight < mid
                if (w < mid) continue;

                // Intermediate nodes must be online
                if (v != n - 1 && !online[v]) continue;

                dp[v] = min(dp[v], dp[u] + (long long)w);
            }
        }

        return dp[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n);

        int high = 0;

        // Build graph
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            indegree[v]++;
            high = max(high, w);
        }

        // Topological Sort (Kahn's Algorithm)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto &[v, w] : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        int low = 0;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid, adj, topo, online, k, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};