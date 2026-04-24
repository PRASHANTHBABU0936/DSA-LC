class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int n = strs.size();
        string hell=strs[0];
        int j = 0;
        int k = 0;
        bool value=true;
        while(j<hell.size()){
        for(int i=1;i<n;i++){
if(hell[j] != strs[i][j]){
value=false;
break;
}
        }
     if(value == true) res.push_back(hell[j]);
     else return res;
     j++;
    }return res;}
};