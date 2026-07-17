class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
          vector<vector<string>> res;
          vector<string> hell=strs;
        //   if(n == 1) return strs;
        //   if (strs == strs.empty()) return "";/
        // if (n == 1) return strs[0];
        if (strs.empty()) return {};

          for(int i=0;i<n;i++){
sort(hell[i].begin(),hell[i].end());
          }
unordered_map <string,vector<int>> mp;

for(int k=0;k<hell.size();k++){
    // if(mp.find(hell[k]) == mp.end()){
mp[hell[k]].push_back(k);
    // }
}


for(auto ed:mp){
    vector<int> hell=ed.second;
    vector<string> pushs;
    for(int l=0;l<hell.size();l++){
pushs.push_back(strs[hell[l]]);
    }
    res.push_back(pushs);
}
    return res;}
};