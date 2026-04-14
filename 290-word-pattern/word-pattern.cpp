class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        int m = s.size();
        unordered_map <char,string> mp;
        unordered_map <string,char> mp2;
vector<string> res;
int j = 0;
for(int i=0;i<m;i++){
    if(s[i] == ' '){
                res.push_back(s.substr(j, i - j));
                        j=i+1;
    }
}

 res.push_back(s.substr(j, m - j));
         if(res.size() != n) return false;

int h=0;
int l=0;
mp[pattern[h]]=res[l];
mp2[res[l]]=pattern[h];
h++;
l++;
while(h < n){
    if(mp.find(pattern[h]) != mp.end()){
        if(mp[pattern[h]] != res[l]) return false;
    } else {
        mp[pattern[h]] = res[l];
    }

    if(mp2.find(res[l]) != mp2.end()){
        if(mp2[res[l]] != pattern[h]) return false;
    } else {
        mp2[res[l]] = pattern[h];
    }

    h++;
    l++; 
}

    




//     if(h < n-1 || l < n-1){
// return false;}

return true;
    }
};