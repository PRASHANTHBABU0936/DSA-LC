class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int n = strs.size();
        map<string,vector<int>> mp;
        for(int i=0;i<n;i++){
            string hell=strs[i];
          sort(hell.begin(),hell.end());
            mp[hell].push_back(i);
        }

        for(auto it:mp){
        vector<string> temp;
        for(auto nn:it.second){
            temp.push_back(strs[nn]);
        }
res.push_back(temp);

            }    
            return res;}
};