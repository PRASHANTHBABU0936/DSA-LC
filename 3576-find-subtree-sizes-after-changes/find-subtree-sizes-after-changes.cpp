class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> ch(n);
        for (int i = 1; i < n; i++) ch[parent[i]].push_back(i);

        vector<int> np(parent), prev(n, -1), order, sz(n, 1);
        order.reserve(n);
        int last[26];
        fill(last, last + 26, -1);

        vector<pair<int,int>> st;   // (node, 0 = enter, 1 = exit)
        st.push_back({0, 0});
        while (!st.empty()) {
            auto [u, state] = st.back();
            st.pop_back();
            int c = s[u] - 'a';
            if (state == 0) {
                if (u != 0 && last[c] != -1) np[u] = last[c];
                prev[u] = last[c];
                last[c] = u;
                order.push_back(u);
                st.push_back({u, 1});
                for (int v : ch[u]) st.push_back({v, 0});
            } else {
                last[c] = prev[u];  // restore on exit
            }
        }

        for (int i = n - 1; i >= 1; i--) {
            int u = order[i];
            sz[np[u]] += sz[u];
        }
        return sz;
    }
};