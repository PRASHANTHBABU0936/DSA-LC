class Solution {
public:
vector<vector<int>> dp;
bool hell(int n,vector<int>& nums,int index,int sum,int curr){

    if(index == n) return curr == sum/2;
// if(index > n)return false;
if(curr == (sum/2)) return true;
  if (dp[index][curr] != -1)
            return dp[index][curr];

        return dp[index][curr]=(hell(n,nums,index+1,sum,curr+nums[index])|| hell(n,nums,index+1,sum,curr));}
    bool canPartition(vector<int>& nums) {
 int sum=0;
        int n = nums.size();
               for(int i=0;i<n;i++){
            sum+=nums[i]; }
            if (sum % 2 != 0) return false;

 int curr=0;
 dp.assign(n,vector<int>(sum+1,-1));
   return hell(n,nums,0,sum,curr);  }
};