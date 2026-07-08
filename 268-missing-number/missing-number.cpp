class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i=0;

long long hell = n*(n+1)/2;
long long sum=0;
        for(int j=0;j<n;j++){
 sum+=nums[j];
        }

 return sum == hell?0:hell-sum;   }
};