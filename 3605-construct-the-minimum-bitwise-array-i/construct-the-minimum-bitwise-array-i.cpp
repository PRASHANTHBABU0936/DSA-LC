class Solution {
public:
void hell(int ele,vector<int> &res){
for(int i=1;i<ele;i++){
if ((i | (i + 1)) == ele){
        res.push_back(i);
        return ;
    }
}
res.push_back(-1);
return;}
    vector<int> minBitwiseArray(vector<int>& nums) {
         vector<int> res;
         int n = nums.size();
         for(int i=0;i<n;i++){
            hell(nums[i],res);}

    return res;}
};