class Solution {
public:
    string ans = "";
    int cnt = 0;

    void solve(int n, int k, string &temp) {
        if (temp.length() == n) {
            cnt++;
            if (cnt == k) ans = temp;
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!temp.empty() && temp.back() == ch) continue;

            temp.push_back(ch);
            solve(n, k, temp);
            temp.pop_back();

            if (ans != "") return;
        }
    }

    string getHappyString(int n, int k) {
        string temp = "";
        solve(n, k, temp);
        return ans;
    }
};