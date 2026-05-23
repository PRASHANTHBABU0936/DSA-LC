class Solution {
public:
    bool check(int len, vector<int>& nums, vector<long long>& power) {
        int n = nums.size();
        const long long base = 1000003;
        const long long mod = 1e9 + 7;

        unordered_map<long long, int> mp;
        long long hash = 0;

        for(int i = 0; i < len; i++)
            hash = (hash * base + nums[i]) % mod;

        mp[hash]++;

        for(int i = len; i < n; i++) {
            hash = (hash - nums[i - len] * power[len - 1] % mod + mod) % mod;
            hash = (hash * base + nums[i]) % mod;
            mp[hash]++;
        }

        for(auto &it : mp) {
            if(it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const long long base = 1000003;
        const long long mod = 1e9 + 7;

        vector<long long> power(n + 1, 1);
        for(int i = 1; i <= n; i++)
            power[i] = (power[i - 1] * base) % mod;

        int l = 1, r = n, ans = n;

        while(l <= r) {
            int mid = (l + r) / 2;

            if(check(mid, nums, power)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};