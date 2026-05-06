class Solution {
public:
    vector<vector<int> > memo;

    int numDistinct(string s, string t) {
        if (t.length() > s.length()){ return 0;}
        memo.resize(s.length() + 1, vector<int>(t.length() + 1, -1));

        return dfs(s, t, 0, 0);
    }

    int dfs(string s, string t, int i, int j){
        if (j == t.size()){ return 1;}
        if (i == s.size()){ return 0;}
        if(memo[i][j] != -1){ return memo[i][j];}

        int res = dfs(s, t, i + 1, j);
        if (s[i] == t[j]){
            res += dfs(s, t, i + 1, j + 1);
        }

        memo[i][j] = res;
        return res;
    }
};
