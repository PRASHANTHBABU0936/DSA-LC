class Solution {
public:
    int strStr(string haystack, string needle) {
        map <string,int> mp;
        int m = haystack.size();
        int n = needle.size();
for(int i=0;i+n-1<m;i++){
if(haystack.substr(i,n)==needle) return i ;
}
    // for(auto it:mp){
    //     if(it.first == needle) return mp[it.first];
    // }
    // if(mp.find(needle) != mp.end()) return mp[needle];
    return -1;}
};