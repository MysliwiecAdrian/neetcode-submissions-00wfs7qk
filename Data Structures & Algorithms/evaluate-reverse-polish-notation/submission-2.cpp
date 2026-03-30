class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        int a = 0;
        int b = 0;

        for(string c : tokens){
            if (c == "+"){
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(a + b);
            }
            else if (c == "-"){
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(b - a);
            }
            else if (c == "*"){
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(a * b);
            }
            else if (c == "/"){
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(b / a);
            }
            else{
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }
};
