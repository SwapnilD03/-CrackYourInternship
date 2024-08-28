class Solution {
public:
    bool invalid(int r, int c, int n) {
        return (r < 0 || r >= n || c < 0 || c >= n);
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int n, vector<vector<bool>>& visited, vector<vector<int>>& directions, queue<pair<int, int>>& q) {
        if (invalid(r, c, n) || grid[r][c] == 0 || visited[r][c]) {
            return;
        }

        visited[r][c] = true;
        q.push({r, c}); 

        for (auto dir : directions) {
            dfs(grid, r + dir[0], c + dir[1], n, visited, directions, q);
        }
    }

    int bfs(vector<vector<int>>& grid, int n, vector<vector<bool>>& visited, vector<vector<int>>& directions, queue<pair<int, int>>& q) {
        int res = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;

                for (auto dir : directions) {
                    int currR = r + dir[0], currC = c + dir[1];
                    if (invalid(currR, currC, n) || visited[currR][currC]) {
                        continue;
                    }

                    if (grid[currR][currC] == 1) {
                        return res;  
                    }

                    q.push({currR, currC});
                    visited[currR][currC] = true;
                }
            }
            res++;
        }

        return res;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;

        bool found = false;
        for (int r = 0; r < n && !found; r++) {
            for (int c = 0; c < n && !found; c++) {
                if (grid[r][c] == 1) {
                    dfs(grid, r, c, n, visited, directions, q);
                    found = true; 
                }
            }
        }

        return bfs(grid, n, visited, directions, q);
    }
};
