class Fenwick {
public:
    int n;
    vector<int> bit;

    Fenwick(int sz) {
        n = sz;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int OFFSET = n + 2;
        Fenwick ft(2 * n + 5);

        long long ans = 0;
        int pref = 0;

        // Initial prefix sum = 0
        ft.update(OFFSET + 1, 1);

        for (int x : nums) {
            pref += (x == target ? 1 : -1);

            // Count previous prefix sums < current prefix sum
            ans += ft.query(pref + OFFSET);

            // Insert current prefix sum
            ft.update(pref + OFFSET + 1, 1);
        }

        return ans;
    }
};