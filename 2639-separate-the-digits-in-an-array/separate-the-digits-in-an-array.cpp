class Solution {
public:
void hell(vector <int> &res,int n){
    while(n>0){
int h=n%10;
res.push_back(h);
n=n/10;
    }
}

    vector<int> separateDigits(vector<int>& nums){
        int n = nums.size();
        vector<int> res;
        for(int i=n-1;i>=0;i--){
hell(res,nums[i]);

        }
        reverse(res.begin(),res.end());
  return res;  }
};