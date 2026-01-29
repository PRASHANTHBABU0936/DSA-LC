class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n=nums.size();
         vector<int> res;
         map <int,int> mp;
         for(int i=0;i<n;i++){
for(int j = 0;j<nums[i].size();j++){
    mp[nums[i][j]]++;}}

    for(auto it:mp){
        if(it.second >= n){
            res.push_back(it.first);
        }
    }return res;}
};