class Solution {
public:
    int binaryGap(int n) {
        int maxi = 0;      
        int res = 0;       
        bool started = false;  

        while(n > 0) {
            int h = n % 2;

            if(h == 1) {
                if(started) {
                    res = max(res, maxi + 1);
                }
                maxi = 0;          
                started = true;   
            }
            else if(started) {
                maxi++;            
            }

            n = n / 2;
        }

        return res;
    }
};