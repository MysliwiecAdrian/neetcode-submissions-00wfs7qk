class Solution {
public:
    vector<int> res;
    vector<vector<int>> adj;
    vector<int> pq;
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int> >(numCourses);
        pq = vector<int>(numCourses, 0);

        for (auto& prereq : prerequisites){
            pq[prereq[0]]++; // counting number of courses required
            adj[prereq[1]].push_back(prereq[0]); // creating adjacency list
        }

        for (int i = 0; i < numCourses; i++){
            if (pq[i] == 0){
                dfs(i);
            }
        }

        if (res.size() != numCourses){ return {};}
        return res;
    }

    void dfs(int c){
        res.push_back(c);
        pq[c]--;
        for (int n : adj[c]){// iterating through adj list to find root course with no prereq
            pq[n]--;
            if (pq[n] == 0){
                dfs(n);
            } 
        }
    }
};
