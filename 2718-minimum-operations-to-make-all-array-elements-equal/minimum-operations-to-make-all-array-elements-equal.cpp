class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
   int n=nums.size();
     vector<long long> ans;
             sort(nums.begin(), nums.end());
  vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
          for (int q : queries) {

            
            int idx = upper_bound(nums.begin(), nums.end(), q) - nums.begin();

           
            long long leftCost = (long long)q * idx - pref[idx];

            long long rightCost = (pref[n] - pref[idx]) - (long long)q * (n - idx);

            ans.push_back(leftCost + rightCost);
        }

        return ans;   
    }
};