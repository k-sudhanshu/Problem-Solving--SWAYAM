class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    int ans = n+1;
    for (int i = 0; i < n; i++) {
        vector<int> dist(n, -1), parent(n, -1);
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                } else if (v != parent[u]) {
                    ans = min(ans, dist[u] + dist[v] + 1);
                }
            }
        }
    }

    if (ans == n+1) ans = -1;
    return ans;
        
    }
};
