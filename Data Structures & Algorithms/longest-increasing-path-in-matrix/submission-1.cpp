class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, f(i, j, matrix, dp, n, m));
            }
        }

        return ans;
    }

    int f(int i, int j, vector<vector<int>>& matrix,
          vector<vector<int>>& dp, int n, int m) {
        
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 1;

        for (auto &d : directions) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                matrix[ni][nj] > matrix[i][j]) {
                ans = max(ans, 1 + f(ni, nj, matrix, dp, n, m));
            }
        }

        return dp[i][j] = ans;
    }
};