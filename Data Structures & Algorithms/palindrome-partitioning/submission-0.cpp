class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;

        backtrack(res, part, s, 0);

        return res;
    }

    void backtrack(vector<vector<string>>& res, vector<string>& part, string s, int i){
        if (i >= s.length()){ 
            res.push_back(part);
            return;
        }

        for(int j = i; j < s.length(); j++){
            if (palindrome(s, i, j)){
                part.push_back(s.substr(i, j - i + 1));
                backtrack(res, part, s, j + 1);
                part.pop_back();
            }
        }
    }

    bool palindrome(string s, int l, int r){
        while(l <= r){
            if (s[l] != s[r]){
                return false;
            }

            l++;
            r--;
        }
        return true;
    }
};
