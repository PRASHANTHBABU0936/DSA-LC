class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        int c1=0,c2=0,maxi=0,res=0;
        unordered_set <int> st;
        for(int i=0;i<n;i++){
            c1=0,c2=0,maxi=0;
            if(!st.empty()) st.clear();
            for(int j=i;j<n;j++){
                if((nums[j] % 2 == 0) && (st.find(nums[j]) == st.end())){
                    st.insert(nums[j]);
                    c1++;
                    }
       else if((nums[j] % 2 != 0) && (st.find(nums[j]) == st.end())){
                    st.insert(nums[j]);
                    c2++;
                }
                if(c1 == c2) {
maxi=max(maxi,j-i+1);
                }
            }
     res=max(res,maxi);   }
    
    return res;}
};