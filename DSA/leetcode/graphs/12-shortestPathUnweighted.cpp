class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        if(src == dest){
            return 0;
        }
        vector<vector<int>> adj = adjL(V,edges);
        vector<bool> visited(V, false);
        queue<pair<int,int>> q;
        q.push({src, 0});
        
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            for(int i = 0; i < adj[curr.first].size(); i++){
                int neighbour = adj[curr.first][i];
                if(neighbour == dest){
                    return curr.second + 1; //curr is teh parent node and neighbout means 
                    //its just 1 away
                }
                if(visited[neighbour] == false){
                    q.push({neighbour, curr.second +1});
                    visited[neighbour] = true;
                }
            }
        }
        return -1;
    }
    
    
    vector<vector<int>> adjL(int V, vector<vector<int>>& edges){
        vector<vector<int>> adjL(V);
        for(int i = 0 ; i < edges.size(); i++){
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            adjL[src].push_back(dest);
            adjL[dest].push_back(src);
        }
        return adjL;
    }
};
