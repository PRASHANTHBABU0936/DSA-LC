class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        //map
        //freq RRAY
  vector<int> ans;
        unordered_map <int,int> mp;
int n = grid.size();
// int m = grid[0].size();
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(mp.find(grid[i][j]) == mp.end()){
mp[grid[i][j]]++;
        }
        else {
ans.push_back(grid[i][j]);
// break;
        }
    }
}
for(int i=1;i<=(n*n);i++){
    if(mp.find(i) == mp.end()){
        ans.push_back(i);
        break;
    }
}
    return ans;}
};