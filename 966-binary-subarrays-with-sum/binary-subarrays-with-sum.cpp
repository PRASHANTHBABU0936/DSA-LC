class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        if(goal == 0){
    int count = 0, ans = 0;
    for(int x : nums){
        if(x == 0){
            count++;
            ans += count;
        } else {
            count = 0;
        }}return ans;}
    
        int n = nums.size();
        int i = 0;
        int ans = 0;
        int sum = 0;
        int zeroc = 0;

        for(int j = 0; j < n; j++){
            sum += nums[j];

            if(sum > goal){
                while(i <= j && sum > goal){
            sum -= nums[i];
                 i++;
             zeroc = 0;}}

            if(sum==goal){
                int temp = i;
zeroc=0;
                while(temp<=j && nums[temp]==0){
                    zeroc++;
                    temp++;
                }

                ans += zeroc+1;}}

        return ans;
    }
};