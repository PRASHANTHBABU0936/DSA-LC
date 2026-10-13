
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end(), greater<int>());

        long long res = 0;

        if (n % 2 == 0) {
            for (int i = 0; i < n / 2; i++) {
                res += 1LL * nums[i] * nums[i];
            }

            for (int i = n / 2; i < n; i++) {
                res -= 1LL * nums[i] * nums[i];
            }
        } else {
            for (int i = 0; i <= n / 2; i++) {
                res += 1LL * nums[i] * nums[i];
            }

            for (int i = n / 2 + 1; i < n; i++) {
                res -= 1LL * nums[i] * nums[i];
            }
        }

        return res;
    }
};
