class Fancy {
public:
    long long mod = 1e9 + 7;
    vector<long long> arr;
    long long mul, add;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b % 2 == 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }
        return res;
    }

    Fancy() {
        mul = 1;
        add = 0;
    }
    
    void append(int val) {
        long long invMul = power(mul, mod - 2);
        long long x = ((val - add + mod) % mod * invMul) % mod;
        arr.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc) % mod;
    }
    
    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= arr.size())
            return -1;
        
        return (arr[idx] * mul + add) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */