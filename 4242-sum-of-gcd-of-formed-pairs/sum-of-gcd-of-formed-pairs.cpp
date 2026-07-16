class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
int maxi=nums[0];
prefix[0]=nums[0];
long long sum = 0;
for(int i=1;i<n;i++){
    if(nums[i] > maxi) maxi=nums[i];
    prefix[i]=__gcd(nums[i],maxi);}
sort(prefix.begin(),prefix.end());
int l = 0;
int r = n-1;
while(l<r){
    sum+=__gcd(prefix[l],prefix[r]);
    l++;
    r--;
}

    return sum;}
};