class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<int>in(n,0);
        for(int i=0;i<m;i++)
        {
            int from=edges[i][0];
            int to=edges[i][1];
            in[to]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
                ans.push_back(i);
        }
        return ans;

 
    }
};
