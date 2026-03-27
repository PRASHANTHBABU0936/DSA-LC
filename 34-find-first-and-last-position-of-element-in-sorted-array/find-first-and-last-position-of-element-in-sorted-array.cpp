class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0;
        int high=n-1;
        int low1=0;
        int high1=n-1;
        vector<int> hell;


    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid] == target && (mid == 0 || nums[mid-1] != target)){
hell.push_back(mid);
break;
        }
        else if(nums[mid] < target){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }



    while(low1<=high1){
        int mid1=low1+(high1-low1)/2;
        if(nums[mid1] == target && (mid1 == n-1 || nums[mid1+1] != target)){
hell.push_back(mid1);
break;
        }
        else if(nums[mid1] > target){
            high1=mid1-1;
        }
        else {
            low1=mid1+1;
        }
    }

 if(hell.size() == 0) return {-1, -1};  
        return hell;
    } 
};