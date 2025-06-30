class Solution {
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(matrix, dp, i, j));
            }
        }
        return ans;
    }

private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c) {
        if (dp[r][c]) return dp[r][c];

        int n = matrix.size();
        int m = matrix[0].size();
        int maxLen = 1;

        for (auto& d : dirs) {
            int x = r + d[0], y = c + d[1];
            if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > matrix[r][c]) {
                maxLen = max(maxLen, 1 + dfs(matrix, dp, x, y));
            }
        }

        return dp[r][c] = maxLen;
    }
};