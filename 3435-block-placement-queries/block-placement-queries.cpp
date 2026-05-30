
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        
        // ── 1. find upper bound for coordinate space ──────────────────
        int MAXV = 0;
        for (auto& q : queries) MAXV = max(MAXV, q[1]);
        MAXV += 1;

        // ── 2. segment tree (range-max, point-update) ─────────────────
        int N = MAXV + 1;
        vector<int> seg(2 * N, 0);

        auto update = [&](int i, int val) {
            seg[i + N] = val;
            for (i = (i + N) >> 1; i >= 1; i >>= 1)
                seg[i] = max(seg[2*i], seg[2*i+1]);
        };

        // query max in [l, r]  (inclusive)
        auto query = [&](int l, int r) {
            int res = 0;
            for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res = max(res, seg[l++]);
                if (r & 1) res = max(res, seg[--r]);
            }
            return res;
        };

        // ── 3. obstacle set + initialise d[0] ─────────────────────────
        // d[x] = distance from x to the NEXT obstacle to its right
        // Only the LEFT endpoint of each gap needs to be stored in seg tree
        // because d[left] = gap_size >= d[any interior point]
        set<int> obs;
        obs.insert(0);
        obs.insert(MAXV);          // right sentinel

        // gap from 0 → MAXV:  d[0] = MAXV
        update(0, MAXV);

        // ── 4. process queries ────────────────────────────────────────
        vector<bool> ans;

        for (auto& q : queries) {

            if (q[0] == 1) {
                int x = q[1];

                // find left neighbour before inserting
                auto it  = obs.upper_bound(x);   // first obstacle > x
                int left = *prev(it);             // last obstacle <= x (< x guaranteed)

                obs.insert(x);

                // update d[left]: gap from left → x
                update(left, x - left);

                // set d[x]: gap from x → next obstacle (already in obs)
                int right = *next(obs.find(x));
                update(x, right - x);

            } else {
                int x  = q[1];
                int sz = q[2];

                // block of size sz must start at some pos p where p+sz <= x
                // i.e. p <= x - sz, and d[p] >= sz
                if (sz > x) {
                    ans.push_back(false);
                    continue;
                }

                int best = query(0, x - sz);
                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};