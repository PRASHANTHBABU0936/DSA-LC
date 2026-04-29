class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return 0;

        // colSum[c][h] = sum of grid[0..h-1][c], 1-indexed height
        vector<vector<long long>> cs(n, vector<long long>(n + 1, 0));
        for (int c = 0; c < n; c++)
            for (int r = 0; r < n; r++)
                cs[c][r + 1] = cs[c][r] + grid[r][c];

        auto rsum = [&](int c, int lo, int hi) -> long long {
            // sum of rows [lo, hi), 0-indexed, i.e. cs[c][hi] - cs[c][lo]
            if (lo >= hi) return 0;
            return cs[c][hi] - cs[c][lo];
        };

        // dp[currH][prevH]: best score cols 0..i where col i has height currH, col i-1 has height prevH
        // heights in [0, n]
        const int N = n + 1;
        vector<vector<long long>> dp(N, vector<long long>(N, -1));
        vector<vector<long long>> ndp(N, vector<long long>(N, -1));

        // Base: i = 0, currH can be anything, no prevH (use prevH = 0 as sentinel, score = 0)
        for (int h = 0; h <= n; h++) dp[h][0] = 0;

        for (int i = 1; i < n; i++) {
            // For the transition we need, for each (currH, prevH):
            //   max over prevPrevH of dp[prevH][prevPrevH] + rsum(i-1, max(prevH,prevPrevH), currH)
            //   (only when currH > prevH, else the col i-1 right side isn't used)
            //
            // Case A: currH <= prevH
            //   score from col i left side: rsum(i, currH, prevH)
            //   col i-1 right side: 0 (currH <= prevH means col i is not taller)
            //   ndp[currH][prevH] = rsum(i, currH, prevH) + max_{prevPrevH} dp[prevH][prevPrevH]
            //   => need suffMax[prevH] = max over all prevPrevH of dp[prevH][prevPrevH]
            //
            // Case B: currH > prevH
            //   score from col i left side: 0
            //   col i-1 right side: rsum(i-1, max(prevH, prevPrevH), currH)
            //   = rsum(i-1, prevH, currH) - rsum(i-1, prevH, max(prevH,prevPrevH))
            //   = rsum(i-1, prevH, currH) - rsum(i-1, prevH, min(currH, prevPrevH)) [when prevPrevH < currH]
            //   ndp[currH][prevH] = max over prevPrevH of:
            //     dp[prevH][prevPrevH] + rsum(i-1, max(prevH,prevPrevH), currH)
            //   Split on whether prevPrevH <= prevH or prevPrevH in (prevH, currH) or prevPrevH >= currH:
            //   * prevPrevH <= prevH: rsum(i-1, prevH, currH) is constant
            //     => rsum(i-1,prevH,currH) + max_{prevPrevH<=prevH} dp[prevH][prevPrevH]
            //        = rsum(i-1,prevH,currH) + prefMax[prevH][prevH]  (prefix max up to prevH)
            //   * prevPrevH in (prevH, currH): rsum(i-1, prevPrevH, currH)
            //     => max_{prevH < prevPrevH < currH} (dp[prevH][prevPrevH] + rsum(i-1,prevPrevH,currH))
            //        = max_{prevH < prevPrevH < currH} (dp[prevH][prevPrevH] - cs[i-1][prevPrevH]) + cs[i-1][currH]
            //        = cs[i-1][currH] + suffMax2[prevH][currH-1]   (where suffMax2 tracks dp[prevH][k]-cs[i-1][k])
            //   * prevPrevH >= currH: rsum = 0
            //     => max_{prevPrevH >= currH} dp[prevH][prevPrevH] = suffMax[prevH][currH]

            // Precompute for current dp:
            // suffMax[prevH][k] = max over prevPrevH >= k of dp[prevH][prevPrevH]
            // prefMax[prevH][k] = max over prevPrevH <= k of dp[prevH][prevPrevH]
            // suffMax2[prevH][k] = max over prevPrevH in (prevH, k] of (dp[prevH][prevPrevH] - cs[i-1][prevPrevH])

            vector<vector<long long>> suffMax(N, vector<long long>(N + 1, -1e18));
            vector<vector<long long>> prefMax(N, vector<long long>(N + 1, -1e18));
            vector<vector<long long>> suffMax2(N, vector<long long>(N + 1, -1e18));

            for (int p = 0; p <= n; p++) {
                // suffMax[p][k]
                for (int k = n; k >= 0; k--) {
                    suffMax[p][k] = suffMax[p][k + 1];
                    if (dp[p][k] >= 0) suffMax[p][k] = max(suffMax[p][k], dp[p][k]);
                }
                // prefMax[p][k]
                for (int k = 0; k <= n; k++) {
                    prefMax[p][k] = (k > 0 ? prefMax[p][k - 1] : (long long)-1e18);
                    if (dp[p][k] >= 0) prefMax[p][k] = max(prefMax[p][k], dp[p][k]);
                }
            }

            // suffMax2[p][k] = max over pp in (p, k] of (dp[p][pp] - cs[i-1][pp])
            // build for each p, sweeping k from p+1 to n
            for (int p = 0; p <= n; p++) {
                suffMax2[p][p] = -1e18; // empty
                for (int k = p + 1; k <= n; k++) {
                    suffMax2[p][k] = suffMax2[p][k - 1];
                    if (dp[p][k] >= 0)
                        suffMax2[p][k] = max(suffMax2[p][k], dp[p][k] - cs[i - 1][k]);
                }
            }

            for (auto& row : ndp) fill(row.begin(), row.end(), -1);

            for (int currH = 0; currH <= n; currH++) {
                for (int prevH = 0; prevH <= n; prevH++) {
                    long long best = -1e18;
                    if (currH <= prevH) {
                        // Case A
                        long long sm = suffMax[prevH][0]; // max over all prevPrevH
                        if (sm > -1e17)
                            best = max(best, sm + rsum(i, currH, prevH));
                    } else {
                        // Case B: currH > prevH
                        // sub-case 1: prevPrevH <= prevH
                        long long pm = prefMax[prevH][prevH];
                        if (pm > -1e17)
                            best = max(best, pm + rsum(i - 1, prevH, currH));
                        // sub-case 2: prevH < prevPrevH < currH
                        long long sm2 = suffMax2[prevH][currH - 1]; // pp in (prevH, currH-1] => pp in (prevH, currH)
                        if (sm2 > -1e17)
                            best = max(best, sm2 + cs[i - 1][currH]);
                        // sub-case 3: prevPrevH >= currH
                        long long sm3 = suffMax[prevH][currH];
                        if (sm3 > -1e17)
                            best = max(best, sm3); // rsum = 0
                    }
                    if (best > -1e17) ndp[currH][prevH] = best;
                }
            }

            swap(dp, ndp);
        }

        long long ans = 0;
        for (int currH = 0; currH <= n; currH++)
            for (int prevH = 0; prevH <= n; prevH++)
                if (dp[currH][prevH] >= 0)
                    ans = max(ans, dp[currH][prevH]);
        return ans;
    }
};