class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> res;
        vector<bool> visited(adj.size(),false);
        int node = 0;
        vector<int> ans = helper(adj, node, res, visited);
        return ans;
    }
    
    vector<int> helper(vector<vector<int>>& adj, int node, vector<int>& res,vector<bool>& visited){
        res.push_back(node);
        visited[node] = true;
        for(int i = 0; i < adj[node].size(); i++){
            int neighbour = adj[node][i];
            if(visited[neighbour] == false){
                helper(adj, neighbour, res, visited);
            }
        
        }
        return res;
    }
};