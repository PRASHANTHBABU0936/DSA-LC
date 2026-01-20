class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
    int i=0;
    int j=0;
    int res=0;
    while(j<m && i<n){
if(s[j] >= g[i]){
res++;
j++;
i++;
}
else {
    j++;
}
    }
 return res;   }
};