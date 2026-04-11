class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        backtrack(candidates, target, 0, cur, 0);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int i, vector<int>& cur, int total){
        if (total == target){
            res.push_back(cur);
            return;
        }

        if (total > target || i == candidates.size()){
            return;
        }

        cur.push_back(candidates[i]);
        backtrack(candidates, target, i + 1, cur, total + candidates[i]);
        cur.pop_back();

        while (i + 1 < candidates.size() && candidates[i] == candidates[i+1]){
            i++;
        }

        backtrack(candidates, target, i + 1, cur, total);
    }
};
