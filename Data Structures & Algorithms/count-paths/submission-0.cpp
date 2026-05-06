class Solution {
public:
    vector<vector<int>> memo;
    int rows;
    int cols;

    int uniquePaths(int m, int n) {
        memo.resize(m, vector<int>(n, -1));
        rows = m;
        cols = n;

        return dfs(0, 0);
    }

    int dfs(int i, int j) {
        if (i == (rows - 1) && j == (cols - 1)) { return 1;}
        if (i >= rows || j >= cols){ return 0;}

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        memo[i][j] = dfs(i, j + 1) + dfs(i + 1, j);
        return memo[i][j];
    }
};
