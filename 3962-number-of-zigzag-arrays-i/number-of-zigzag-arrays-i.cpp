class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m, 1), down(m, 1);
        vector<long long> new_up(m), new_down(m);
        vector<long long> pref_up(m + 1), pref_down(m + 1);

        for (int len = 2; len <= n; len++) {
            // Build prefix sums
            pref_up[0] = pref_down[0] = 0;
            for (int i = 0; i < m; i++) {
                pref_up[i + 1]   = (pref_up[i]   + up[i])   % MOD;
                pref_down[i + 1] = (pref_down[i] + down[i]) % MOD;
            }

            for (int y = 0; y < m; y++) {
                // new_up[y]: prev was DOWN, need x < y (strictly less)
                new_up[y] = pref_down[y];

                // new_down[y]: prev was UP, need x > y (strictly greater)
                new_down[y] = (pref_up[m] - pref_up[y + 1] + MOD) % MOD;
            }

            swap(up,   new_up);
            swap(down, new_down);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++)
            ans = (ans + up[i] + down[i]) % MOD;

        return (int)ans;
    }
};