class Solution {
public:
    vector<string> res = {"JFK"};

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for (auto& ticket : tickets){
            adj[ticket[0]];
        }
        
        sort(tickets.begin(), tickets.end());
        for (auto& ticket : tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }
        dfs("JFK", adj, tickets.size() + 1);

        return res;
    }

    bool dfs(const string& start, unordered_map<string, vector<string>>& adj, int target){
        if (res.size() == target){ return true;}
        if (adj.find(start) == adj.end()){ return false;}

        vector<string> temp = adj[start];
        for(int i = 0; i < temp.size(); i++){
            string end = temp[i];
            adj[start].erase(adj[start].begin() + i);
            res.push_back(end);

            if (dfs(end, adj, target)) { return true;}

            adj[start].insert(adj[start].begin() + i, end);
            res.pop_back();
        }

        return false;
    }
};
