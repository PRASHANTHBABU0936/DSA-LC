class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        // Prefix sum
        vector<int> prefix(n);
        prefix[0] = nums[0];

        // Suffix sum
        map<int, int> mp;

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        // Store suffix sum -> starting index
        mp[nums[n - 1]] = n - 1;

        int sum = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            sum += nums[i];
            mp[sum] = i;
        }

        int mini = INT_MAX;

        // Case 1: Only suffix
        if (mp.find(x) != mp.end()) {
            mini = n - mp[x];
        }

        // Case 2: Prefix + suffix
        for (int i = 0; i < n; i++) {

            // Case 3: Only prefix
            if (prefix[i] == x) {
                mini = min(mini, i + 1);
            }

            // Prefix + suffix
            if (mp.find(x - prefix[i]) != mp.end()) {

                int j = mp[x - prefix[i]];

                // Avoid overlapping
                if (j > i) {
                    mini = min(mini, (i + 1) + (n - j));
                }
            }
        }

        if (mini == INT_MAX)
            return -1;

        return mini;
    }
};