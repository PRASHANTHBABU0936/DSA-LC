class Solution {
public:
    unordered_set<string> st;
    vector<int> memo; // -1 = unknown, 0 = false, 1 = true

    bool solve(string &s, int start) {
        if (start == s.size()) return true;
        if (memo[start] != -1) return memo[start];

        for (int end = start + 1; end <= s.size(); end++) {
            if (st.count(s.substr(start, end - start))) {
                if (solve(s, end)) {
                    return memo[start] = 1;
                }
            }
        }
        return memo[start] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto &w : wordDict) st.insert(w);
        memo.assign(s.size(), -1);
        return solve(s, 0);
    }
};
