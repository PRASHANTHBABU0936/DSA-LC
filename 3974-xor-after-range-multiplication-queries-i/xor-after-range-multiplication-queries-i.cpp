class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
     int n = nums.size();
     int h;
     int m = queries.size();
     for(int i=0;i<m;i++){
int idx=queries[i][0];
while(idx<=queries[i][1]){
                nums[idx] = (1LL * nums[idx] * queries[i][3]) % 1000000007;
idx+=queries[i][2];}


     }
//  while()
if(n == 1) return nums[0];
int x=nums[0];
for(int j=1;j<n;j++){
x^=nums[j];
}
  return x;  }
};