class Solution {
public:

vector<vector<int>> memo;


int hell(int index,int sum,vector<int> &nums,int n,int carried){

        if (carried == sum)
            return true;

        if (carried > sum)
            return false;
            
if(index == n) return false;
if(memo[index][carried] != -1) return memo[index][carried];
int pres=nums[index];
if(carried+pres == sum) return true;

return memo[index][carried]=(hell(index+1,sum,nums,n,carried+pres))||(hell(index+1,sum,nums,n,carried));
}

    bool canPartition(vector<int>& nums) {
     int n = nums.size();
     long long sum=0;
        for(auto ed:nums){
            sum+=ed;
        }
        // memo.resize(n,vector<int>(n,-1));
        int target = sum / 2;
memo.resize(n, vector<int>(target + 1, -1));

        if(sum%2 != 0) return false;
        return hell(0,sum/2,nums,n,0);

    }
};