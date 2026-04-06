class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char t : tasks){
            count[t-'A']++;
        }

        priority_queue<int> pq;
        for(int c : count){
            if (c > 0){
                pq.push(c);
            }
        }

        int time = 0;
        queue<pair<int,int>> q;
        while (!pq.empty() || !q.empty()){
            time++;
            if (pq.empty()){
                time = q.front().second;
            }
            else{
                int cnt = pq.top() - 1;
                pq.pop();
                if (cnt > 0){
                    q.push({cnt, time + n});
                }
            }

            if (!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
