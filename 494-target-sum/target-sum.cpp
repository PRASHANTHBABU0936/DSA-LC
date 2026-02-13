class Solution {
public:

vector<vector<int>> dp;
int offset;

int hell(int index, vector<int> &nums, int target, int sum) {

    if(index == nums.size()) {
        return (sum == target);
    }

    if(dp[index][sum + offset] != -1)
        return dp[index][sum + offset];

    int takePlus =
        hell(index + 1, nums, target, sum + nums[index]);

    int takeMinus =
        hell(index + 1, nums, target, sum - nums[index]);

    return dp[index][sum + offset] = takePlus + takeMinus;
}

int findTargetSumWays(vector<int>& nums, int target) {

    int total = 0;
    for(int x : nums) total += x;

    offset = total;

    dp.assign(nums.size(), vector<int>(2 * total + 1, -1));

    return hell(0, nums, target, 0);
}
};
