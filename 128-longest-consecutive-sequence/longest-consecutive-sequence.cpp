class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
    //  int n = nums.size();
       set <int> st;
       int c=0;
       int maxi=0;
       for(auto it:nums){
        st.insert(it);}
        for(auto hell:st){
            if(st.find(hell+1) != st.end()){
                c++;
                maxi=max(maxi,c);
            }
            else c=0;
        }
    return maxi+1;}
};