class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        for(int i = 0; i < n; i++) {
            if(lcp[i][i] != n - i) return "";
        }

        string word(n, '?');
        char ch = 'a';

        for(int i = 0; i < n; i++) {
            if(word[i] == '?') {
                if(ch > 'z') return "";
                word[i] = ch;

                for(int j = i + 1; j < n; j++) {
                    if(lcp[i][j] > 0) {
                        word[j] = ch;
                    }
                }
                ch++;
            }
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(word[i] == word[j]) {
                    dp[i][j] = 1;
                    if(i + 1 < n && j + 1 < n)
                        dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }

        if(dp != lcp) return "";

        return word;
    }
};