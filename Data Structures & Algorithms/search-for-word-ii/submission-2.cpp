class Solution {
public:
    vector<string> res;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size();
        int cols = board[0].size();

        for (auto& word : words){
            auto& copy = board;
            bool check = false;
            for (int r = 0; r < rows && !check; r++){
                for (int c = 0; c < cols; c++){
                    if (dfs(r, c, board, word, 0)){
                        res.push_back(word);
                        check = true;
                        break;
                    }
                }
            }
            board = copy;
        }
    
        return res;
    }

    bool dfs(int r, int c, vector<vector<char>>& board, string word, int i){
        if (i == word.size()){ return true;}

        if (r < 0 || c < 0 || r > board.size() - 1 || c > board[0].size() - 1 || board[r][c] == '#' || board[r][c] != word[i]){
            return false;
        }

        board[r][c] = '#';
        bool sol = dfs(r + 1, c, board, word, i + 1) || dfs(r - 1, c, board, word, i + 1) ||
                    dfs(r, c + 1, board, word, i + 1) || dfs(r, c - 1, board, word, i + 1);
        board[r][c] = word[i];
        return sol;
    }
};
