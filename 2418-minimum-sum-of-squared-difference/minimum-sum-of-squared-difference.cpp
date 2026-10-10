
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        int high = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            high = max(high, diff[i]);
            total += diff[i];
        }

        if (total <= k) return 0;

        int low = 0;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long ops = 0;

            for (int d : diff) {
                if (d > mid) ops += d - mid;
            }

            if (ops <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int limit = low;
        long long ops = 0;
        long long ans = 0;

        for (int d : diff) {
            if (d > limit) {
                ops += d - limit;
                d = limit;
            }
            ans += 1LL * d * d;
        }

        long long remaining = k - ops;

        // Reduce 'remaining' differences equal to limit by one.
        for (int d : diff) {
            if (remaining == 0) break;

            if (d >= limit && limit > 0) {
                ans -= 1LL * limit * limit;
                ans += 1LL * (limit - 1) * (limit - 1);
                remaining--;
            }
        }

        return ans;
    }
};
