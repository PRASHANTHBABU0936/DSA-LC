class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
int col=n/rows;
int h = 0;
map<pair<int,int>, char> mp;
for(int i=0;i<rows;i++){
    for(int j=0;j<col;j++){
mp[{i,j}] = encodedText[h];
    h++;}}
string res="";
for(int j = 0; j < col; j++) {

    int i = 0;
    int k = j;

    // start from (0, j)
    while(i < rows && k < col) {
        res += mp[{i, k}];
        i++;
        k++;
    }
}
for(int i=res.size()-1;i>=0;i--){
    if(res[i] == ' '){
    while(res[i] == ' '){
        res.pop_back();
    }} else {break;}}


    return res;}
};