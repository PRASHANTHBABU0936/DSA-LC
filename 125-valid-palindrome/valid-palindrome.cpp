class Solution {
public:
bool hell(string s){
    int i=0;
    int j=s.size()-1;
    while(i<j){
if(s[i] == s[j]) {
    i++;
    j--;
}
else return false;
    }
return true;}

    bool isPalindrome(string s) {
        int n = s.size();
        string nam="";
        for(int i=0;i<n;i++){
                if(isalnum(s[i])){         
                nam += tolower(s[i]);  
            }
  }  
        return hell(nam);
    }
};