class Solution {
public: 
    vector<string> res;
    map<char, string> nums = {
        {'2', "abc" }, 
        {'3', "def"}, 
        {'4', "ghi"}, 
        {'5', "jkl"}, 
        {'6', "mno"}, 
        {'7', "pqrs"}, 
        {'8', "tuv"}, 
        {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()){ return res;}

        backtrack(0, "", digits);

        return res;
    }

    void backtrack(int i, string part, string digits){
        if (part.length() == digits.length()){
            res.push_back(part);
            return;
        }

        string chars = nums[digits[i]];
        for(char c : chars){
            backtrack(i + 1, part + c, digits);
        }
    }

};
