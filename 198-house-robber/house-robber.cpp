class Solution {
public:
vector<int> dp;

int hell(int index,vector <int> &nums,int n){
    if(index>=n) return 0;
        if (dp[index] != -1)
            return dp[index];
        int take=nums[index]+hell(index+2,nums,n);
        int nottake=hell(index+1,nums,n);
                return dp[index] = max(take, nottake);
}

    int rob(vector<int>& nums) {
      int n = nums.size();
    //   vector<int> dp();
       dp.resize(n, -1); 
return hell(0,nums,n);  
    }
};