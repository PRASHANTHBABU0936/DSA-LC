class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string res = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '*' && (res.size() >= 1)) {
                res.erase(res.size()-1);
            } else if (s[i] == '#' && (res.size() >= 1)) {
                res += res;
            } else if (s[i] == '%' && (res.size() >= 2)) {
                reverse(res.begin(), res.end());
            } else if(isalpha(s[i])){
                res.push_back(s[i]);}
            
        }
        return res;
    }
};