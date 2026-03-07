class Solution {
public:
    int minFlips(string s) {
         int n = s.size();
        string t = s + s;

        int alt1 = 0, alt2 = 0;
        int ans = INT_MAX;

        for(int i = 0; i < t.size(); i++) {

            if(t[i] != (i % 2 ? '1' : '0')) alt1++;
            if(t[i] != (i % 2 ? '0' : '1')) alt2++;

            if(i >= n) {
                if(t[i-n] != ((i-n) % 2 ? '1' : '0')) alt1--;
                if(t[i-n] != ((i-n) % 2 ? '0' : '1')) alt2--;
            }

            if(i >= n-1) {
                ans = min(ans, min(alt1, alt2));
            }
        }

        return ans;
    }
};