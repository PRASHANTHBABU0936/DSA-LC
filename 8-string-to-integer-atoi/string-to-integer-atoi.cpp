class Solution {
public:
    int myAtoi(string s) {
        string res = "";
        int n = s.size();
        bool hell = false;
        bool hell2 = false;
        bool signUsed = false;

        for(int i = 0; i < n; i++){
            if(!hell2 && !signUsed && s[i] == ' ') continue;

            else if((s[i] == '-' || s[i] == '+') && !hell2){
                if(signUsed) return 0;
                signUsed = true;
                hell = (s[i] == '-');
            }

            else if(s[i] >= '0' && s[i] <= '9'){
                hell2 = true;
                res += s[i];
            }

            else{
                break;
            }
        }

        if(res.empty()) return 0;

        long long finale;

        try {
            finale = stoll(res);
        } catch(...) {
            return hell ? INT_MIN : INT_MAX; 
        }

        if(hell) finale = -finale;

        if(finale > INT_MAX) return INT_MAX;
        if(finale < INT_MIN) return INT_MIN;

        return (int)finale;
    }
};