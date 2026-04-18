class Solution {
public:
int reverse(int n){
    int m=0;
    while(n>0){
m=m*10+n%10;
n=n/10;
    }
    return m;
}
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};