//BFS
class Solution {
public:
    bool ans = true;
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<int> color(graph.size(), 0);
        
        for(int i = 0 ; i < graph.size(); i++){
            if(visited[i] == false){
                dfs(graph, i, visited, color);
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& graph,int node ,vector<bool>& visited,vector<int>& colorArr){
        visited[node] = true;
        int color = colorArr[node];
        for(int i = 0 ; i < graph[node].size(); i++){
            int neighbour = graph[node][i];
            if(visited[neighbour] == false){
                //if not visited color it opposite
                if(color == 0){
                    colorArr[neighbour] = 1;
                }else{
                    colorArr[neighbour] = 0;
                }
                dfs(graph, neighbour , visited, colorArr);
            }else{
                // if visited check color
                if(color == colorArr[neighbour]){
                    ans = false;
                }
            }
        }
    }
};

//dfs
class Solution {
public:
    bool ans = true;
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<int> color(graph.size(), 0);
        
        for(int i = 0 ; i < graph.size(); i++){
            if(visited[i] == false){
                dfs(graph, i, visited, color);
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& graph,int node ,vector<bool>& visited,vector<int>& colorArr){
        visited[node] = true;
        int color = colorArr[node];
        for(int i = 0 ; i < graph[node].size(); i++){
            int neighbour = graph[node][i];
            if(visited[neighbour] == false){
                //if not visited color it opposite
                if(color == 0){
                    colorArr[neighbour] = 1;
                }else{
                    colorArr[neighbour] = 0;
                }
                dfs(graph, neighbour , visited, colorArr);
            }else{
                // if visited check color
                if(color == colorArr[neighbour]){
                    ans = false;
                }
            }
        }
    }
};