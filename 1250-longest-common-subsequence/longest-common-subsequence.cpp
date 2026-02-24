class Solution {
public:
vector<vector<int>> dp;

int hell(string &text1, string &text2, int i, int j){ 
 if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i] == text2[j])
            return dp[i][j]=1 + hell(text1, text2, i - 1, j - 1);

  return dp[i][j] = max(
            hell(text1, text2, i - 1, j),
            hell(text1, text2, i, j - 1)
        );
}
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.assign(n,vector<int>(m, -1));
        return hell(text1,text2,n-1,m-1);
    }
};