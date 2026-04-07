class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums, 0, subset, res);
        return res;
    }

    void backtrack(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res){
        if (i >= nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtrack(nums, i + 1, subset, res);
        subset.pop_back();
        backtrack(nums, i + 1, subset, res);
    }
};
