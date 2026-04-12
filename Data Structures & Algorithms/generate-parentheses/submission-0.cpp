class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        string s;
        backtrack(0, 0, n, s);
        return res;
    }

    void backtrack(int open, int close, int n, string& s){
        if (open == close && open == n){
            res.push_back(s);
            return;
        }

        if (open < n){
            s += '(';
            backtrack(open + 1, close, n, s);
            s.pop_back();
        }

        if (close < open){
            s += ')';
            backtrack(open, close + 1, n, s);
            s.pop_back();
        }
    }
};
