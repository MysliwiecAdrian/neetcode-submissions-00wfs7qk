class Solution {
public:
    vector<vector<int> > memo; //using int to store 1 as true, 0 as false
    int m;
    int n;

    bool isMatch(string s, string p) {
        m = s.length();
        n = p.length();
        memo.resize(m + 1, vector<int>(n + 1, -1));

        return dfs(s, p, 0, 0);
    }

    bool dfs(string s, string p, int i, int j){
        if (j == n){ return i == m;} // checks when we reach end of p if s has become a match
        if (memo[i][j] != -1){ return memo[i][j];}

        bool check = (i < m && (s[i] == p[j] || p[j] == '.')); // checks if i is inbounds and char are equal
        if ((j + 1 < n) && (p[j + 1] == '*')){
            memo[i][j] = dfs(s, p, i, j + 2) || (check && dfs(s, p, i + 1, j));
        }
        else {
            memo[i][j] = check && dfs(s, p, i + 1, j + 1);
        }

        return memo[i][j];
    }   
};
