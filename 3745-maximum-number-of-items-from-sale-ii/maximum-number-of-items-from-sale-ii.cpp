class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> cnt(n + 1, 0);
        for (auto &it : items) cnt[it[0]]++;

        // tot[f] = number of items whose factor is a multiple of f
        vector<int> tot(n + 1, 0);
        for (int f = 1; f <= n; f++)
            for (int m = f; m <= n; m += f)
                tot[f] += cnt[m];

        long long pmin = LLONG_MAX;
        vector<pair<long long, long long>> v; // {price, gain}
        for (auto &it : items) {
            pmin = min(pmin, (long long)it[1]);
            long long g = tot[it[0]] - 1; // exclude the item itself
            if (g > 0) v.push_back({it[1], g});
        }
        sort(v.begin(), v.end());

        long long R = budget, k = 0;
        for (auto &[p, g] : v) {
            if (p >= 2 * pmin) break;      // no better than two cheapest copies
            long long t = min(g, R / p);
            k += t;
            R -= t * p;
            if (t < g) break;              // can't afford more at this price or higher
        }
        return (int)(2 * k + R / pmin);
    }
};