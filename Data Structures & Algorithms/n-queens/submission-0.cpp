class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    vector<vector<string>> res;


    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        backtrack(0, n, board);
        return res;
    }

    void backtrack(int r, int n, vector<string>& board){
        if (r == n){
            res.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++){
            if (col.count(i) || posDiag.count(r + i) ||
                negDiag.count(r - i)) {
                continue;
            }

            col.insert(i);
            posDiag.insert(r + i);
            negDiag.insert(r - i);
            board[r][i] = 'Q';

            backtrack(r + 1, n, board);

            col.erase(i);
            posDiag.erase(r + i);
            negDiag.erase(r - i);
            board[r][i] = '.';
        }
    }
};
