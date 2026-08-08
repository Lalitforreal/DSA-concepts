class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        int n = V;
        int INF = 1e8;
        vector<int> res(n, INF);
        res[src] = 0;
        for(int i = 0; i < n - 1; i++){//for n-1 pass
            for(int j = 0; j < edges.size(); j++){ //for edges traversal
                
                int s = edges[j][0];
                int dest = edges[j][1];
                int wt = edges[j][2];
                
                if(res[s] != 1e8 && res[s] + wt < res[dest]){
                    //relaxation
                    res[dest] = res[s] + wt;
                }
            }
            
        }
        
        //now check for negative cycle if any node gets relaxed after n-1 return -1
        for(int j = 0; j < edges.size(); j++){
                int s = edges[j][0];
                int dest = edges[j][1];
                int wt = edges[j][2];
                
                if(res[s] != 1e8 && res[s] + wt < res[dest]){
                    //relaxation
                    return {-1};
                }
        }
        return res;
    }
};
