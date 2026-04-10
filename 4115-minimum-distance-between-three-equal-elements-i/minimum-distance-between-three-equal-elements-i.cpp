class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        // store indices for each value (1 to n)
        vector<vector<int>> pos(n + 1);

        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        for (int val = 1; val <= n; val++) {
            if (pos[val].size() >= 3) {
                vector<int>& v = pos[val];

                for (int i = 0; i + 2 < v.size(); i++) {
                    int dist = 2 * (v[i + 2] - v[i]);
                    ans = min(ans, dist);
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};