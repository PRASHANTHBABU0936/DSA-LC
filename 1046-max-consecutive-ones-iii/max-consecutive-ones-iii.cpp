class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int sum=0;
        int zeroc=0;
        int res=0;
        for(int j=0;j<n;j++){
            if(nums[j] == 0) zeroc++;
            // if(zeroc>k){
while(zeroc>k){
    if(nums[i] == 0){
        zeroc--;
    }
    sum--;
    i++;
// }
}
sum++;
res=max(res,sum);

        }
    return res;}
};