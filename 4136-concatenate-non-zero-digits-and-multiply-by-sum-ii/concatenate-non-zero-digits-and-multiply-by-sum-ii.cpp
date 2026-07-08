class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // Store non-zero digits and their positions
        vector<int> digits, pos;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digits.size();

        // Prefix sum of digits
        vector<long long> prefSum(m + 1, 0);

        // Prefix concatenation modulo MOD
        vector<long long> prefNum(m + 1, 0);

        // Powers of 10 modulo MOD
        vector<long long> pow10(m + 1, 1);

        for (int i = 0; i < m; i++) {
            prefSum[i + 1] = prefSum[i] + digits[i];
            prefNum[i + 1] = (prefNum[i] * 10 + digits[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            // first non-zero digit >= l
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            // last non-zero digit <= r
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R + 1] - prefSum[L];

            long long x = (prefNum[R + 1]
                          - prefNum[L] * pow10[R - L + 1] % MOD
                          + MOD) % MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};