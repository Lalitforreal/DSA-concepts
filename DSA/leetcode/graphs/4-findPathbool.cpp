
//LC 1971
// There is a bi-directional graph with n vertices,
// where each vertex is labeled from 0 to n - 1 (inclusive)
// The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi.
// Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
// You want to determine if there is a valid path that exists from vertex source to vertex destination.
// Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
// Example 1:
// Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
// Output: true
// Explanation: There are two paths from vertex 0 to vertex 2:
// - 0 → 1 → 2
// - 0 → 2


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList = listH( n,  edges);
        //traverse
        vector<bool> visited(n,false);
        bool ans = helper(adjList, source, visited, source, destination);
        return ans;

    }

    bool helper(vector<vector<int>>& adj, int node,vector<bool>& visited, int source, int destination ){
        visited[node] = true;
        //src will always be true as we are passing it as param
        if(node == destination){
            return true;
        }
        for(int i = 0; i < adj[node].size(); i++){
            int neighbour = adj[node][i];
            if(visited[neighbour] == false){
                bool ans = helper(adj, neighbour, visited, source, destination);
                if(ans == true){
                    return true;
                }
            }
        }
        return false;
    }

    vector<vector<int>> listH(int n, vector<vector<int>>& edges){
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        return adj;
    }
};