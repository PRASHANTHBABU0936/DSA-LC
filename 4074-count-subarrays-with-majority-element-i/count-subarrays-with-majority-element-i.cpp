class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int freq = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] == target)
                    freq++;

                if (2 * freq > (j - i + 1))
                    ans++;
            }
        }

        return ans;
    }
};