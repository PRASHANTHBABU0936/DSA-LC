class Solution {
public:
 int dp[1001][1001];
int c=0;
int hell(int idx1,int idx2,string &text1,string &text2){
    if(idx1 == text1.size() || idx2 == text2.size()){
        return 0;}
         if(dp[idx1][idx2] != -1) return dp[idx1][idx2]; 
    int g=0;
if(text1[idx1] == text2[idx2]){
   return dp[idx1][idx2] = 1+hell(idx1+1,idx2+1,text1,text2);}
   
        return dp[idx1][idx2]= max(hell(idx1+1, idx2, text1, text2),hell(idx1, idx2+1, text1, text2));
    }
    // return g;

    int longestCommonSubsequence(string text1, string text2) {
    //   int c=0;
       memset(dp, -1, sizeof(dp));
    return  hell(0,0,text1,text2);}
};