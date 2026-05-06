class Solution {
public:
    vector<vector<int> > memo;

    int longestCommonSubsequence(string text1, string text2) {
        memo.resize(text1.length(), vector<int>(text2.length(), -1));
        return dfs(text1, text2, 0, 0);
    }

    int dfs(string text1, string text2, int i, int j){
        if (i == text1.size() || j == text2.size()) { return 0;} // when lengths of strings are same we have reached end
        if (memo[i][j] != -1) { return memo[i][j];} // storing history to prevent repeats

        if (text1[i] == text2[j]) {
            memo[i][j] = 1 + dfs(text1, text2, i + 1, j + 1); // move diagonally when both found
        } else {
            memo[i][j] = max(dfs(text1, text2, i + 1, j), dfs(text1, text2, i, j + 1)); // check down and right on grid
        }
        
        return memo[i][j];
    }
};
