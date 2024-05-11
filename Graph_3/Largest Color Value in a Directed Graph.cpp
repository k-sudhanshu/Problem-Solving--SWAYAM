class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> indeg(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }
        queue<int> zeroIndegree;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                zeroIndegree.push(i);
            }
        }
        vector<vector<int>> counts(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            counts[i][colors[i] - 'a']++;
        }
        int maxCount = 0;
        int visited = 0;
        while (!zeroIndegree.empty()) {
            int u = zeroIndegree.front();
            zeroIndegree.pop();
            visited++;
            for (int v : graph[u]) {
                for (int i = 0; i < 26; i++) {
                    counts[v][i] = max(counts[v][i], counts[u][i] + (colors[v] - 'a' == i ? 1 : 0));
                }
                indeg[v]--;
                if (indeg[v] == 0) {
                    zeroIndegree.push(v);
                }
            }
            maxCount = max(maxCount, *max_element(counts[u].begin(), counts[u].end()));
        }
        return visited == n ? maxCount : -1;
    }
};
