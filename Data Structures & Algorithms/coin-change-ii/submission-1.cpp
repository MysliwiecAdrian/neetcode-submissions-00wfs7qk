class Solution {
public:
    vector<vector<int> > memo;

    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        memo.resize(coins.size() + 1, vector<int>(amount + 1, -1));

        return dfs(coins, 0, amount);
    }

    int dfs(vector<int>& coins, int i, int a) {
        if (a == 0){ return 1;}
        if (i >= coins.size()){ return 0;}
        if (memo[i][a] != -1){ return memo[i][a];}

        int res = 0;
        if (a >= coins[i]) {
            res = dfs(coins, i + 1, a);
            res += dfs(coins, i, a - coins[i]);
        }

        memo[i][a] = res;
        return res;
    }
};