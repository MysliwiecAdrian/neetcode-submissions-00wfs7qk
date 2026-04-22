class Solution {
public:
    unordered_map<int, vector<int> > prereq;
    unordered_set<int> visited;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++){
            prereq[i] = {};
        }

        for (auto& pr : prerequisites){
            prereq[pr[0]].push_back(pr[1]);
        }

        for(int j = 0; j < numCourses; j++){
            if (!dfs(j)){
                return false;
            }
        }

        return true;
    }

    bool dfs(int c){
        if (visited.count(c)) { return false;}
        if (prereq[c].empty()) { return true;}

        visited.insert(c);
        for (int p : prereq[c]){
            if (!dfs(p)){
                return false;
            }
        }

        visited.erase(c);
        prereq[c].clear();
        return true;
    }
};
