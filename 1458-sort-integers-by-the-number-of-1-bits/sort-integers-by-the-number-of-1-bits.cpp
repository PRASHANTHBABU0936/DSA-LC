class Solution {
public:
int hell(int h){
      int c = 0;
        while(h > 0){
            if(h % 2 == 1)
                c++;
            h = h / 2;
        }
        return c;}
    vector<int> sortByBits(vector<int>& arr) {
       
        sort(arr.begin(), arr.end(), [&](int a, int b){

            int c1 = hell(a);
            int c2 = hell(b);

            if(c1 == c2)
                return a < b;   // normal ascending

            return c1 < c2;    // less set bits first
        });

        return arr;

    }
};