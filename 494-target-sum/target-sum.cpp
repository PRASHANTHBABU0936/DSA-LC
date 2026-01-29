class Solution {
public:
vector<vector<int>> dp;
int total;
int hell(int sum,int index,vector<int>& nums,int target){
if (index == nums.size()) {
    return (sum == target) ? 1 : 0;
}
       if (dp[index][sum + total] != -1)
            return dp[index][sum + total];

        return dp[index][sum + total] =
 hell(sum+nums[index],index+1,nums,target)+
hell(sum-nums[index],index+1,nums,target);

}
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        total = 0;
        for (int x : nums) total += x;
dp.assign(nums.size(), vector<int>(2 * total + 1, -1));
        return hell(0,0,nums,target);
    }
};