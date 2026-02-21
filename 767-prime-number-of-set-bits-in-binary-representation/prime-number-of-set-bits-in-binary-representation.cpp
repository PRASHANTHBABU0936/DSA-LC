class Solution {
public:
bool prime(int nums){
    if(nums < 2) return false;

    for(int i = 2; i * i <= nums; i++){
        if(nums % i == 0){
            return false;
        }
    }
    return true;
}

    int countPrimeSetBits(int left, int right) {
       int reall=0;
        for(int i=left;i<=right;i++){
            int h = i;
            int c=0;
            while(h>0){
if(h%2 == 1) c++;
h=h/2;
            }
            if(prime(c)) reall++;
        }
    return reall;}
};