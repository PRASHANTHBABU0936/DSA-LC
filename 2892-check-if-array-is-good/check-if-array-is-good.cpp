class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int hell=*max_element(nums.begin(),nums.end());
        vector<int> res(hell+1,hell);
        for(int j=1;j<=hell;j++){
            res[j-1]=j;
        }
         sort(nums.begin(),nums.end());
        if(res.size() != nums.size()) return false;
       
      if(res != nums){
return false;
     }
    return true;}
};