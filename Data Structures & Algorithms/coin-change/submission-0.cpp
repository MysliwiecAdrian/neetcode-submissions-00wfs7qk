class Solution {
public:
    unordered_map<int, int> memo;

    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(amount, coins);
        if (res == INT_MAX){
            return -1;
        }

        return res;
    }

    int dfs(int amount, vector<int>& coins){
        if (amount == 0){ return 0;}
        if (memo.find(amount) != memo.end()){ return memo[amount];}

        int res = INT_MAX;
        for(int c : coins){
            if (amount - c >= 0){
                int result = dfs(amount - c, coins);
                if (result != INT_MAX){
                    res = min(res, 1 + result);
                }
            }
        }

        memo[amount] = res;
        return res;
    }
};
