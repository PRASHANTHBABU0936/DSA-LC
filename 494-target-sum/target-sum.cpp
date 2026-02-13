class Solution {
public:
void hell(int index,vector <int> &nums,int target,int sum,int &c){
 if(index == nums.size()) {
    if(target == sum) {
        c++;
    }
    return;   // IMPORTANT
}


hell(index+1,nums,target,sum+nums[index],c);
hell(index+1,nums,target,sum-nums[index],c);

}
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int c=0;
 hell(0,nums,target,sum,c);
 return c;
    }
};