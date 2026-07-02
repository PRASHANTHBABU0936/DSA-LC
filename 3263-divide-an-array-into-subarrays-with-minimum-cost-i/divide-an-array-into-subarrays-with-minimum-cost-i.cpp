class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int hell=nums[0];
        // sort(nums.begin(),nums.end());
int c=1;
int mini=INT_MAX;
int mini2=INT_MAX;

for(int i=1;i<n;i++){
if(nums[i]<=mini){
    mini2=mini;
    mini=nums[i];}
else if(nums[i]<=mini2){
mini2=nums[i];
}
}
        // if(nums[0] != sum) sum+=nums[0]+nums[1];
        // else sum+=nums[1]+nums[2];
  return sum+mini+mini2;  }
};