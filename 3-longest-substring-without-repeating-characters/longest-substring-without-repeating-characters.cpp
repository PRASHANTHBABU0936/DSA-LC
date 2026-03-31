class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> st;
        int n = s.size();
        if(n == 0 || n == 1){
            return n;
        }
        int i = 0;
        
        int j = 0;
        int res=0;
        while(i<=j && j<n){
if (!st.empty() && st.find(s[j]) != st.end()) {
    res=max(res,j-i);
st.clear();
i++;
j=i;
            }
            else {
                st.insert(s[j]);
    j++;        }
        }
            if(!st.empty()){
            res = max(res, j - i);}
    return res;}
};