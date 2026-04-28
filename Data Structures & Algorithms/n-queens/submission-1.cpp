class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> col;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;

    vector<vector<string>> solveNQueens(int n) {
        string temp = "";
        for (int i = 0; i < n; i++){
            temp += '.';
        }
        vector<string> board(n, temp);
        backtrack(board, n, 0);

        return res;
    }

    void backtrack(vector<string>& board, int n, int r){
        if (r == n){
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++){
            if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c)){ continue;}

            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = 'Q';

            backtrack(board, n, r + 1);

            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';
        }
    }
};
