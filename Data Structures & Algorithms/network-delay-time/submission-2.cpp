struct Node {
    int weight;
    int target;

    bool operator>(const Node& other) const { //needed for minHeap, error without it
        return this->weight > other.weight; 
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int> > > edges;
        for (const auto& time : times){
            edges[time[0]].emplace_back(time[1], time[2]); //adjacency list
        }

        priority_queue<Node, vector<Node>, greater<Node>> minHeap; //pq to store nearest neighbor with lowest weight as root
        Node root = {0, k};
        minHeap.push(root);
        set<int> visited;
        int t = 0;

        while (!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();
            int weightOne = curr.weight;
            int nodeOne = curr.target;
            
            if (visited.count(nodeOne)){ continue;}
            visited.insert(nodeOne);
            t = weightOne;

            if (edges.count(nodeOne)){
                for (const auto& next : edges[nodeOne]){
                    int nodeTwo = next.first;
                    int weightTwo = next.second;
                    if (!visited.count(nodeTwo)){
                        Node nextNode = {weightTwo + weightOne, nodeTwo};
                        minHeap.push(nextNode);
                    }
                }
            }
        }

        if (visited.size() == n){
            return t;
        }

        return -1;
    }
};
