class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> curr(k, 0);

            int rem = num % k;

            // Subarray containing only the current element
            curr[rem]++;

            // Extend all subarrays ending at the previous index
            for (int r = 0; r < k; r++) {
                int newRem = (r * rem) % k;
                curr[newRem] += dp[r];
            }

            // Add counts of subarrays ending at this index
            for (int r = 0; r < k; r++) {
                ans[r] += curr[r];
            }

            dp = curr;
        }

        return ans;
    }
};