class Solution {
public:
    const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) result[i][i] = 1;

        while (exp) {
            if (exp & 1) result = multiply(result, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return result;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        int size = 2 * m;
        Matrix T(size, vector<long long>(size, 0));

        // Build transitions
        for (int x = 0; x < m; x++) {
            // up -> down (y > x)
            for (int y = x + 1; y < m; y++) {
                T[y][m + x] = 1;
            }
            // down -> up (y < x)
            for (int y = 0; y < x; y++) {
                T[m + y][x] = 1;
            }
        }

        // Compute T^(n-1)
        Matrix Tn = power(T, n - 1);

        // Initial vector = all 1s
        vector<long long> V(size, 1);

        // Multiply Tn * V
        vector<long long> result(size, 0);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i] = (result[i] + Tn[i][j] * V[j]) % MOD;
            }
        }

        long long ans = 0;
        for (auto x : result) ans = (ans + x) % MOD;

        return ans;
    }
};