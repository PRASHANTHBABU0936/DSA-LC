class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1]<9){
        digits[n-1]++;
        return digits;}
        else {
             int h = n-1;
  digits[h]++;
            while(digits[h] > 9){
            if(h == 0){
vector<int> hell(n+1);
hell[0]=1;
hell[1]=0;
if(hell.size()>2){
for(int i=2;i<n;i++){
    hell[i+1]=digits[i];
}}
return hell; }
            digits[h]=0;
          digits[h-1]++;
            h--; }}
    return digits;}
};