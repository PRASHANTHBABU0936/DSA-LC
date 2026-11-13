class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

        // cost of raising [p..e] up to nums[p]
        auto seg = [&](int p, int e) -> long long {
            return 1LL * nums[p] * (e - p + 1) - (pre[e + 1] - pre[p]);
        };

        deque<int> dq;
        long long cost = 0, ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            // l absorbs chain elements that are <= nums[l]
            while (!dq.empty() && nums[dq.front()] <= nums[l]) {
                int p = dq.front();
                dq.pop_front();
                int e = dq.empty() ? r : dq.front() - 1;
                cost -= seg(p, e);
            }
            int e = dq.empty() ? r : dq.front() - 1;
            cost += seg(l, e);
            dq.push_front(l);

            // shrink the right end until the cost fits in k
            while (cost > k) {
                int p = dq.back();
                cost -= seg(p, r);
                r--;
                if (p > r) dq.pop_back();
                else cost += seg(p, r);
            }
            ans += r - l + 1;
        }
        return ans;
    }
};