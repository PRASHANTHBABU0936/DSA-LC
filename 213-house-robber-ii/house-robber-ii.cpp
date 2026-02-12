class Solution {
public:
vector <int> dp;
   int hell(int index, vector<int> &nums, int n) {
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        int take = nums[index] + hell(index + 2, nums, n);
        int nottake = hell(index + 1, nums, n);
        return dp[index]=max(take, nottake);
    }
    int rob(vector<int>& nums) {
                int n = nums.size();                
        if(n == 1) 
            return nums[0];
  dp.assign(n,-1);
                    int case1 = hell(0, nums, n-1);
          dp.assign(n,-1);
        int case2 = hell(1, nums, n);
        return max(case1, case2);
    }
};