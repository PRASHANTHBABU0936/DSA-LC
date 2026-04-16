class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        
        for (int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (int q : queries) {
            auto& v = pos[nums[q]];
            
            if ((int)v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            int idx = (int)(lower_bound(v.begin(), v.end(), q) - v.begin());
            int sz = (int)v.size();
            int best = INT_MAX;
            
            // Left neighbor (linear distance, since v is sorted)
            if (idx - 1 >= 0)
                best = min(best, q - v[idx - 1]);
            else
                // Wrap: q is left of all others, nearest via wrap is v[sz-1]
                best = min(best, n - v[sz - 1] + q);
            
            // Right neighbor
            if (idx + 1 < sz)
                best = min(best, v[idx + 1] - q);
            else
                // Wrap: q is right of all others, nearest via wrap is v[0]
                best = min(best, n - q + v[0]);
            
            ans.push_back(best);
        }
        
        return ans;
    }
};