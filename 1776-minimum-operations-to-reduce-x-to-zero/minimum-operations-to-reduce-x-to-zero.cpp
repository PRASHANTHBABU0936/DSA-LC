class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        // suffix sum -> starting index
        map<int, int> mp;

        int sum = 0;

        // Empty suffix
        mp[0] = n;

        for (int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            mp[sum] = i;
        }

        int mini = INT_MAX;
        int pre = 0;

        // i = -1 represents an empty prefix
        for (int i = -1; i < n; i++) {

            if (i >= 0)
                pre += nums[i];

            int need = x - pre;

            if (mp.find(need) != mp.end()) {

                int j = mp[need];

                // Prefix and suffix must not overlap
                if (j >= i + 1) {

                    int operations = (i + 1) + (n - j);

                    mini = min(mini, operations);
                }
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};