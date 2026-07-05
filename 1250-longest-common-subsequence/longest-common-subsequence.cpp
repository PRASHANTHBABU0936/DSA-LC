class Solution {
public:
vector<vector<int>> dp;
int hell(string &text1, string &text2,int n,int m,int index1,int index2){
if(index1 > n-1 || index2 > m-1) return 0;
if(dp[index1][index2] != -1) return dp[index1][index2];
else if(text1[index1] == text2[index2]) return dp[index1][index2]=1+hell(text1,text2,n,m,index1+1,index2+1);

else return dp[index1][index2]=max(hell(text1,text2,n,m,index1+1,index2),hell(text1,text2,n,m,index1,index2+1));

return dp[index1][index2];}
    int longestCommonSubsequence(string text1, string text2) {
      int n=text1.size();
      int m = text2.size();
dp.assign(n, vector<int>(m, -1));       return  hell(text1,text2,n,m,0,0);
    }
};