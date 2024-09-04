class Solution {
public:
    const int MOD = 1000000007;

    int determinant(vector<vector<int>>& mat, int n) {
        vector<vector<int>> temp = mat; 
        int det = 1;
        for (int i = 0; i < n; i++) {
            
            int pivot = i;
            while (pivot < n && temp[pivot][i] == 0) {
                pivot++;
            }
            if (pivot == n) {
                return 0;  
            }
            if (i != pivot) {
                swap(temp[i], temp[pivot]);
                det = (MOD - det) % MOD;  
            }
            
            
            det = (int64_t(det) * temp[i][i]) % MOD;
            int inv = modInverse(temp[i][i], MOD);
            for (int j = i + 1; j < n; j++) {
                int factor = (int64_t(temp[j][i]) * inv) % MOD;
                for (int k = i; k < n; k++) {
                    temp[j][k] = (temp[j][k] - int64_t(temp[i][k]) * factor % MOD + MOD) % MOD;
                }
            }
        }
        return det;
    }

    int modInverse(int a, int m) {
        int m0 = m, t, q;
        int x0 = 0, x1 = 1;

        if (m == 1) return 0;

        while (a > 1) {
            q = a / m;
            t = m;
            m = a % m, a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }

        if (x1 < 0) x1 += m0;

        return x1;
    }

    int countSpanningTrees(vector<vector<int>>& Graph, int n, int m) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int u = Graph[i][0];
            int v = Graph[i][1];
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        
        vector<vector<int>> laplacian(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    for (int k = 0; k < n; k++) {
                        laplacian[i][i] += graph[i][k];
                    }
                } else if (graph[i][j] > 0) {
                    laplacian[i][j] = -graph[i][j];
                }
            }
        }

        
        vector<vector<int>> minorMatrix(n - 1, vector<int>(n - 1, 0));
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                minorMatrix[i][j] = laplacian[i][j];
            }
        }

        
        return determinant(minorMatrix, n - 1);
    }
};
