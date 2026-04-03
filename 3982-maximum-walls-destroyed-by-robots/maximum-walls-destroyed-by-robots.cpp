class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<pair<int,int>> bots(n);
        for (int i = 0; i < n; i++) bots[i] = {robots[i], distance[i]};
        sort(bots.begin(), bots.end());
        sort(walls.begin(), walls.end());

        auto countWalls = [&](long long lo, long long hi) -> long long {
            if (lo > hi) return 0;
            int l = (int)(lower_bound(walls.begin(), walls.end(), (int)lo) - walls.begin());
            int r = (int)(upper_bound(walls.begin(), walls.end(), (int)hi) - walls.begin());
            return r - l;
        };

        // Robot 0 base case
        long long dp0 = countWalls(bots[0].first - bots[0].second, bots[0].first);
        long long dp1 = countWalls(bots[0].first, n > 1
                            ? min((long long)bots[0].first + bots[0].second, (long long)bots[1].first - 1)
                            : (long long)bots[0].first + bots[0].second);

        for (int i = 1; i < n; i++) {
            long long pos  = bots[i].first,  dist = bots[i].second;
            long long ppos = bots[i-1].first, pdist = bots[i-1].second;

            // Left range: always capped by previous robot (fixed obstacle)
            long long ll = max(pos - dist, ppos + 1), lh = pos;

            // Right range: capped by next robot
            long long rl = pos;
            long long rh = (i + 1 < n)
                         ? min(pos + dist, (long long)bots[i+1].first - 1)
                         : pos + dist;

            long long wl = countWalls(ll, lh);
            long long wr = countWalls(rl, rh);

            // Overlap = walls in (prev's actual RIGHT range) ∩ (curr's actual LEFT range)
            // prev RIGHT hi is capped by its own distance AND by current robot
            // curr LEFT lo is already ll = max(pos-dist, ppos+1)
            // Intersection = [ll, min(ppos + pdist, pos - 1)]
            long long ov = countWalls(ll, min(ppos + pdist, pos - 1));

            // Transitions:
            // dp[i][L] from dp[i-1][L]: no overlap (prev ended at ppos, curr starts at ppos+1)
            // dp[i][L] from dp[i-1][R]: subtract overlap (prev right and curr left can share walls)
            // dp[i][R] from either:     no overlap (prev right ends at pos-1, curr right starts at pos)
            long long new_dp0 = max(dp0 + wl, dp1 + wl - ov);
            long long new_dp1 = max(dp0, dp1) + wr;

            dp0 = new_dp0;
            dp1 = new_dp1;
        }

        return (int)max(dp0, dp1);
    }
};