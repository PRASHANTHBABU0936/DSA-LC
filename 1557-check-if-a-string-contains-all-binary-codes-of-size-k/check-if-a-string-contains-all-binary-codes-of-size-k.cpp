class Solution {
public:
    bool hasAllCodes(string s, int k) {

        if (k > s.size()) return false;

        unordered_set<int> seen;
        int window = 0;

        for (int i = 0; i < s.size(); i++) {

            window = ((window << 1) & ((1 << k) - 1)) | (s[i] - '0');

            if (i >= k - 1) {
                seen.insert(window);
            }
        }

        return seen.size() == (1 << k);
    }
};