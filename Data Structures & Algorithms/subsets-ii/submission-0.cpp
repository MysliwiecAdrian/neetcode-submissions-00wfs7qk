class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(res, 0, {}, nums);
        return res;
    }

    void backtrack(vector<vector<int>>& res, int i, vector<int> subset, vector<int>& nums){
        if (i == nums.size()){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(res, i + 1, subset, nums);
        subset.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        backtrack(res, i + 1, subset, nums);

    }
};
