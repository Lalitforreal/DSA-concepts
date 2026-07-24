class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        queue<int> q;
        vector<int> res;
        vector<bool> visited(adj.size(), false);
        
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int i = 0; i < adj[node].size(); i++){
                int neighbour = adj[node][i];
                if(visited[neighbour] == false){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return res;
    }
};