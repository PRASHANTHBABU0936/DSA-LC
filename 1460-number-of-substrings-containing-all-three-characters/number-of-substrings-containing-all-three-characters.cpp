class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        int res=0;
        int count=0;
        unordered_map <int,int> mp;
      for(int j=0;j<n;j++){
// st.insert(s[j]);mp
mp[s[j]]++;
     while (mp.size() == 3) {
                res += (n - j);   
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }

// res+=1+count;

      }
    return res;}
};