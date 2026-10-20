class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> s = nums;
        sort(s.begin(), s.end());

        vector<int> lps(n);
        vector<int> pi(n, 0);

        // Check every divisor k
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int i = 0; i < n && valid; i += k) {
                // Check if sorted block s[i..i+k-1]
                // is a cyclic rotation of nums[i..i+k-1].
                vector<int> pattern(s.begin() + i, s.begin() + i + k);

                vector<int> lps(k, 0);

                for (int j = 1, len = 0; j < k;) {
                    if (pattern[j] == pattern[len]) {
                        lps[j++] = ++len;
                    } else if (len > 0) {
                        len = lps[len - 1];
                    } else {
                        lps[j++] = 0;
                    }
                }

                bool found = false;
                int j = 0;

                for (int t = 0; t < 2 * k - 1; t++) {
                    int x = nums[i + (t % k)];

                    while (j > 0 && x != pattern[j])
                        j = lps[j - 1];

                    if (x == pattern[j])
                        j++;

                    if (j == k) {
                        found = true;
                        break;
                    }
                }

                if (!found) valid = false;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};