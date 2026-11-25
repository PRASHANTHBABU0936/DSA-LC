class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sa(n), rk(n), tmp(n);
        for (int i = 0; i < n; i++) { sa[i] = i; rk[i] = nums[i]; }

        // Suffix array by prefix doubling, O(n log^2 n)
        for (int k = 1;; k <<= 1) {
            auto cmp = [&](int a, int b) {
                if (rk[a] != rk[b]) return rk[a] < rk[b];
                int ra = a + k < n ? rk[a + k] : -1;
                int rb = b + k < n ? rk[b + k] : -1;
                return ra < rb;
            };
            sort(sa.begin(), sa.end(), cmp);
            tmp[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            rk = tmp;
            if (rk[sa[n - 1]] == n - 1) break;
        }

        // Kasai: lcp[r] = LCP of suffixes sa[r] and sa[r+1]
        vector<int> lcp(n, 0);
        for (int i = 0, h = 0; i < n; i++) {
            if (rk[i] + 1 < n) {
                int j = sa[rk[i] + 1];
                while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) h++;
                lcp[rk[i]] = h;
                if (h) h--;
            } else {
                h = 0;
            }
        }

        // Shortest unique prefix of each suffix
        int ans = n;
        for (int r = 0; r < n; r++) {
            int m = max(r > 0 ? lcp[r - 1] : 0, r + 1 < n ? lcp[r] : 0);
            int len = m + 1;
            if (sa[r] + len <= n) ans = min(ans, len);
        }
        return ans;
    }
};