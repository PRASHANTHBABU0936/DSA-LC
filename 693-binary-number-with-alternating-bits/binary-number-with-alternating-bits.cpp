class Solution {
public:
    bool hasAlternatingBits(int n) {
        int h = -1;
        while(n>0){
            if(h == n%2) return false;
            h=n%2;
            n=n/2;
        }
    return true;}
};