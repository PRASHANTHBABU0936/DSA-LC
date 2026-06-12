class Solution {
public:
    bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxi=0;
        for(int i=0;i<n;i++){
            if(i > maxi) return false;
            if(i == n-1) return true;
maxi=max(maxi,i+nums[i]);
        }
    return true;}
};