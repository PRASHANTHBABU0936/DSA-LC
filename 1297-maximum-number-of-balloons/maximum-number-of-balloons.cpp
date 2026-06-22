class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int hell = text.size();
        // unordered_map <int>
        int b=0,l=0,n=0,a=0,o=0;

        // vector<int> freq(5,0);
        for(int i=0;i<hell;i++){
if(text[i] == 'b') b++;
else if(text[i] == 'a'){a++;}
else if(text[i] == 'l'){l++;}
else if(text[i] == 'o'){o++;}
else if(text[i] == 'n'){n++;}
        }


        // if(b == a && b == n){
        //     if(l == (b*2) && o == (b*2)){
        //         return b;
        //     }
        // }
int c=0;
 while(b>0){
           if(b>=1 && a>=1 && n>=1 && l>=2 && o>=2){
            b--;
            a--;
            l-=2;
            o-=2;
            n-=1;
            c++;} 
else {
    return c;}}
        
    return c;}
};