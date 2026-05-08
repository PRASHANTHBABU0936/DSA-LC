class Solution {
public:
    
    bool isPrime(int n) {

        if (n == 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        for (int i=3; i*i<=n; i++) {
            if (n % i == 0) return false;
        }

        return true;
    }

    // return only prime factor like 2 -> [2, 4, 6, 8] 2 is prime and return all prime factor
    vector<int> getPrimeFactor(int x) {

        vector<int> factor;

        for (int p=2; p*p<=x; p++) {

            if (x % p == 0) {
                factor.push_back(p);

                // because jo prime number nahi hai wo bhi aa jayega like
                // 18 toh 2, 3, 4 6 bhi aa jayega but huma chaiys bss 2, 3 toh us number sa 
                // pora divide kar denga
                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        if (x > 1) factor.push_back(x);

        return factor;
    }

    int minJumps(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, vector<int>> map;
        queue<pair<int, int>> q; // {i, steps}
        vector<bool> visited(n, false);
        unordered_set<int> usedPrime;

        for (int i=0; i<n; i++) {
            
            vector<int> factor = getPrimeFactor(nums[i]);

            for (int f : factor) {
                map[f].push_back(i);
            }
        }

        q.push({0, 0});
        visited[0] = true;


        while (!q.empty()) {
            auto[i, steps] = q.front();
            q.pop();

            if (i == n-1) {
                return steps;
            }

            if (i-1 >= 0 && !visited[i-1]) {
                visited[i] = true;
                q.push({i-1, steps+1});
            }

            if (i+1 < n && !visited[i+1]) {
                visited[i+1] = true;
                q.push({i+1, steps+1});
            }

            int val = nums[i];

            if (isPrime(val) && !usedPrime.count(val)) {
                usedPrime.insert(val);

                for (int idx : map[val]) {

                    if (visited[idx]) continue;
                    visited[idx] = true;
                    q.push({idx, steps+1});
                }
            }
        }
        
        return -1;
    }
};