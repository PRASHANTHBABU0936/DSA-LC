class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        // Step 1: compute final length
        for(char c : s){
            if(islower(c)) len++;
            else if(c == '*') len = max(0LL, len - 1);
            else if(c == '#') len = min(len * 2, (long long)1e18);
            else if(c == '%') {
                // length unchanged
            }
        }

        if(k >= len) return '.';

        // Step 2: reverse simulate
        for(int i = s.size() - 1; i >= 0; i--){
            char c = s[i];

            if(islower(c)){
                if(k == len - 1) return c;
                len--;
            }
            else if(c == '*'){
                len++; // undo deletion
            }
            else if(c == '#'){
                if(k >= len / 2) k -= len / 2;
                len /= 2;
            }
            else if(c == '%'){
                if(len > 1){
                    k = len - k - 1;
                }
            }
        }

        return '.';
    }
};