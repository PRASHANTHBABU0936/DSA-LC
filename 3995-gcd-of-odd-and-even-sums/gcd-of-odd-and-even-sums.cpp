class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sum1=0;
        long long sum2=0;
        for(int i=1;i<=2*n;i++){
           if(i%2 != 0) sum1+=i;
            if(i%2 == 0) sum2+=i;
        }
    return __gcd(sum1,sum2);}
};