class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int count =1,count1=1;
        int n = nums.size();
        int res=1;
        for(int i=1;i<n;i++){
            if(nums[i-1] > nums[i]){
                count++;
                res=max(res,count);
            }
            else{
                count=1;
            }
        }

     for(int i=1;i<n;i++){
            if(nums[i-1] < nums[i]){
                count1++;
                res=max(res,count);
                  res=max(res,count1);
            }
            else{
                count1=1;
            }
        }

    return res;}
};