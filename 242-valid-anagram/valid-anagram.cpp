class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        vector<int> freq1(26,0);
                vector<int> freq2(26,0);

        for(int i=0;i<n;i++){
freq1[s[i]-'a']++;
        }
        for(int j=0;j<n;j++){
freq2[t[j]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
return true;    }
};