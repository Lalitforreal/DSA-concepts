//DEPENDENCIES inj types
class Solution {
  public:
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> indegree(V);
        vector<vector<int>> adjL(V);
        adj(V, edges, adjL, indegree);
        queue<int> q;
        //now push all the indegree 0 in q
        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> res;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int i = 0; i < adjL[node].size();i++){
                int neighbour = adjL[node][i];
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        return res;
    }
    
    void adj(int V, vector<vector<int>>& edges,vector<vector<int>>& adjL,vector<int>& indegree){
        for(int i = 0 ; i < edges.size(); i++){
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            adjL[src].push_back(dest);
            indegree[dest]++; // imp
        }
    }
};