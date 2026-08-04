class Solution {
  public:
  
    struct cmp{
        //if cmp a,b == true b priority if not a priority 
        bool operator()(const pair<int,int>& a,const pair<int,int>& b){
            return a.first > b.first; //min heap
        }
    };
    
    
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here 
        vector<int> dist(V, INT_MAX);
        vector<vector<pair<int,int>>> adj = adjL(V,edges);
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        //pq sttores dist, node
        dist[src] = 0;
        
        pq.push({dist[src], src});
        //push it
        
        while(!pq.empty()){
            pair<int,int> node = pq.top();
            int d = node.first;
            int curr = node.second;
            pq.pop();
            for(int i = 0; i < adj[curr].size(); i++){
                pair<int,int> neighbour = adj[curr][i];
                if(d + neighbour.second < dist[neighbour.first]){
                    //update dist and push in pq
                    dist[neighbour.first] = d + neighbour.second;
                    pq.push({dist[neighbour.first], neighbour.first}); //new dist, node
                }
                
            }
        }
        return dist;
    }
    
    vector<vector<pair<int,int>>> adjL(int V, vector<vector<int>> &edges){
        vector<vector<pair<int,int>>> adj(V); //vector<pair<neighbour of index, wt>>;

        for(int i = 0; i < edges.size(); i++){
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            int wt = edge[2];
            
            adj[src].push_back({dest, wt});
            adj[dest].push_back({src, wt});
            
        }
        return adj;
    }
};