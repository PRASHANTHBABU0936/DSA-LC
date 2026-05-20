class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
         vector<int> res(n);
         int c=0;
         unordered_set <int> st;
         for(int i=0;i<n;i++){
st.insert(A[i]); c++;
st.insert(B[i]); c++;

if(st.size() != c) res[i]=c-st.size();
else res[i]=0;

         }
    return res;}
};