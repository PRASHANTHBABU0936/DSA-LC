class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {

            // If already sorted
            if (nums[low] <= nums[high])
                return nums[low];

            int mid = low + (high - low) / 2;

            // Safe check
            if (mid > 0 && mid < n-1 &&
                nums[mid] < nums[mid+1] &&
                nums[mid] < nums[mid-1])
                return nums[mid];

            if (nums[low] <= nums[mid]) {
                low = mid + 1;      // ❌ removed high = n-1
            } else {
                high = mid - 1;     // ❌ removed low = 0
            }
        }

        return nums[low];
    }
};