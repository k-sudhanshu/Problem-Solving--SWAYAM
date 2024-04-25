class Solution {
private:
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        if(visited[node])
            return visited[node];
        
        Node* cloned = new Node(node->val);
        visited[node] = cloned;
        
        for(auto nei: node->neighbors){
            cloned->neighbors.push_back(cloneGraph(nei));
        }
        return cloned;
        
    }
};
