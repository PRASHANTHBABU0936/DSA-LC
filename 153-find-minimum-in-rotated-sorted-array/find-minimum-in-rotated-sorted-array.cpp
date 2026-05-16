class Solution {
public:
    int findMin(vector<int>& nums) {
        // vector<int> hell;
        // hell.push_back(sort(nums.begin(),nums.end()));
        vector<int> hell = nums;
sort(hell.begin(), hell.end());
        if(hell == nums) return nums[0];
        int low=0;
        int n=nums.size();
        int high=n-1;
        if(n == 2) {
            if(nums[0]>nums[1]) return nums[1];
       else {
        return nums[0];
       }
        }

        while(low<=high){
int mid=(low+high)/2;
if(mid == n-1 ||   (nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1])){
return nums[mid];
}
else if(nums[0]<=nums[mid]){
// if()
low=mid+1;
}
else {
high=mid-1;
}
        }
    return nums[low];}
};