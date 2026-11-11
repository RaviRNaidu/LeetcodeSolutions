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
    Node* dfs(unordered_map<Node*, Node*>& mpp, Node* node){
        if(node == NULL){
            return node;
        }

        if(mpp.count(node)){
            return mpp[node];
        }

        Node* newNode = new Node(node->val);
        mpp[node] = newNode; 

        for(auto it : node->neighbors){
            newNode->neighbors.push_back(dfs(mpp, it));
        }

        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mpp;
        return dfs(mpp, node);
    }
};