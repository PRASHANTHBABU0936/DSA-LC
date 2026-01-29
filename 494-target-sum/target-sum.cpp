class Solution {
public:
int hell(int sum,int index,vector<int>& nums,int target){
if (index == nums.size()) {
    return (sum == target) ? 1 : 0;
}

return hell(sum+nums[index],index+1,nums,target)+
hell(sum-nums[index],index+1,nums,target);

}
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        return hell(0,0,nums,target);
    }
};