class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1){ return false;}

        vector<vector<int> > adj(n);
        for (auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        if (!dfs(0, -1, visited, adj)){ return false;}

        return visited.size() == n;
    }

    bool dfs(int node, int par, unordered_set<int>& visited, vector<vector<int>>& adj){
        if (visited.count(node)){ return false;}

        visited.insert(node);
        for (int n : adj[node]){
            if (n == par){ continue;}
            if (!dfs(n, node, visited, adj)){ return false;}
        }

        return true;
    }
};
