class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
unordered_set <int> st;
for(int num : arr1) {   
    string s = to_string(num);
    for(int i = 1; i <= s.size(); i++){
       st.insert(stoi(s.substr(0, i)));
    }
}

int res=0;
for(int num2:arr2){
    string s = to_string(num2);
    for(int i = 1; i <= s.size(); i++){ 
        if(st.find(stoi(s.substr(0, i))) != st.end()){
res = max(res,i);        }
}

    }return res;}
};