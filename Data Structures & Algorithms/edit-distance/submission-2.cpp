class Solution {
public:
    vector<vector<int> > memo;
    int m;
    int n;

    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        memo.resize(m, vector<int>(n, -1));

        return dfs(word1, word2, 0, 0);
    }

    int dfs(string word1, string word2, int i, int j){
        if (i == m){ return n - j;} // base case for when i reaches end so remained is adding all operations
        if (j == n){ return m - i;} // base case for when j reaches end
        if (memo[i][j] != -1){ return memo[i][j];} //storing for existence

        if (word1[i] == word2[j]){
            memo[i][j] = dfs(word1, word2, i + 1, j + 1); // move diagonally if chars match
        }
        else{
            int ins = dfs(word1, word2, i, j + 1); // inserting keeps i in place so that when can increment j
            int del = dfs(word1, word2, i + 1, j); // deleting means we move on from curr char with i
            int rep = dfs(word1, word2, i + 1, j + 1); // replacing means current index will match so checking next

            memo[i][j] = min(ins, min(del, rep)) + 1; // smallest value will be stored
        }

        return memo[i][j];
    }
};
