class Solution {
public:
    vector<vector<int> > directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int> > memo;
    int rows;
    int cols;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        memo.resize(rows, vector<int>(cols, -1));
        
        int res = 0;
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                res = max(res, dfs(matrix, r, c, INT_MIN));
            }
        }

        return res;
    }

    int dfs(vector<vector<int>>& matrix, int r, int c, int curr){
        if (r < 0 || r >= rows || c < 0 || c >= cols || matrix[r][c] <= curr) { return 0;}
        if (memo[r][c] != -1){ return memo[r][c];}

        int res = 1;
        for(auto d : directions){
            res = max(res, 1 + dfs(matrix, r + d[0], c + d[1], matrix[r][c]));
        }

        memo[r][c] = res;
        return res;
    }
};
