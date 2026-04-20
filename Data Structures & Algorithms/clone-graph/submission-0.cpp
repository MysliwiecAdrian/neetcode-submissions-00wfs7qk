/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> clone;
        return dfs(node, clone);
    }

    Node* dfs(Node* node, map<Node*, Node*>& clone){
        if (node == nullptr){ return nullptr;}
        if (clone.count(node)){ return clone[node];}

        Node* copy = new Node(node->val);
        clone[node] = copy;
        for (auto next : node->neighbors){
            copy->neighbors.push_back(dfs(next, clone));
        }

        return copy;
    }
};
