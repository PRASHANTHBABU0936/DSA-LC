class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
            for (int n : nums) {

            if (n == 2) {
                res.push_back(-1);
                continue;}
  int temp = n;
            int k = 0;

            while (temp & 1) {
                k++;
                temp >>= 1;
            }   
            int ans = n - (1 << (k - 1));
            res.push_back(ans);
        
            }
        return res;}
               
};