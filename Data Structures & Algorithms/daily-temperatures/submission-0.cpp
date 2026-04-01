class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> val;
        stack<int> index;

        for(int i = 0; i < temperatures.size(); i++){
            int t = temperatures[i];
            while(!val.empty() && t > val.top()){
                int valTop = val.top();
                int indexTop = index.top();
                val.pop();
                index.pop();
                res[indexTop] = i - indexTop;
            }
            val.push(temperatures[i]);
            index.push(i);
        }

        return res;
    }
};
