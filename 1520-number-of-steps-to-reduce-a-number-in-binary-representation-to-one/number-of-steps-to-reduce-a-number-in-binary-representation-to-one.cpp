class Solution {
public:
string addOne(string s) {
    int n = s.length();

    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '0') {
            s[i] = '1';
            return s;  
        }
        s[i] = '0';    
    }

    return "1" + s; }      
    int numSteps(string s) {
        int c=0;
while(!(s.size() == 1 && s[0] == '1')){       if(s[s.size()-1] == '0') {
                s.pop_back();
            }
            else{
s=addOne(s);
            }
c++;}
 return c;   }
};