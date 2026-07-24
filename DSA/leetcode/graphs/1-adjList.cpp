class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i = 0 ; i < edges.size(); i++){
            pair<int,int> edge = edges[i];
            int src = edge.first;
            int dest = edge.second;
            
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        return adj;
    }
};