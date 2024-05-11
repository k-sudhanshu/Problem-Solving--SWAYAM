class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //normal diskasta ka code likho uske baad varitaion lagayenge
         vector<vector<vector<int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v, w});
        }

        // Using a tuple (distance, node, stops) in the priority queue
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        
        vector<int> d(n, INT_MAX);
        d[src] = 0;
        q.push({0, src, 0}); // Starting from source with 0 stops

        while (!q.empty()) {
            int dis = get<0>(q.top());
            int u = get<1>(q.top());
            int stops = get<2>(q.top());
            q.pop();
            
            // If the current distance is greater than the recorded distance or if the number of stops exceeds k, skip
            if (dis > d[u] || stops > k) continue;

            // Traverse adjacent nodes
            for (auto v : adj[u]) {
                int node = v[0];
                int price = v[1];
                if (price + dis < d[node]) {
                    d[node] = price + dis;
                    q.push({d[node], node, stops + 1}); // Increment stops
                }
            }
        }

        return d[dst] == INT_MAX ? -1 : d[dst];
    }
};
