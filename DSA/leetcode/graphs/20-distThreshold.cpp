//LC 1334

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap

        vector<int> dist(n, INT_MAX);
        vector<vector<pair<int,int>>> adj = adjL(n,edges);
        pair<int,int> bestCount = { INT_MIN , INT_MAX}; //city, count

        for(int src = 0; src < n; src++){
            // make each node src once 0-n
            pq.push({0, src});
            dist[src] = 0;

            while(!pq.empty()){
                int d = pq.top().first; //dist from src - just for pq
                int node = pq.top().second;
                pq.pop();
                if(d > dist[node]) continue; //no need to relax
                for(auto& neighbour : adj[node]){
                    //neighour is a pair<dNode, wt>
                    int wt = neighbour.second;
                    int dNode = neighbour.first;

                    if(dist[node] + wt  < dist[dNode]){
                        dist[dNode] = dist[node] + wt;
                        pq.push({dist[dNode], dNode});
                    }
                }
            }

            //after one src done calc count and bestCount
            int count = 0;
            for(int j = 0; j < dist.size();j++){
                if(j != src && dist[j] <= distanceThreshold){
                    count++;
                }
                //reset
                dist[j] = INT_MAX;
            }
            if(count <= bestCount.second){
                bestCount.first = src ; //loop runs 0->n so src > prev
                bestCount.second = count;
            }

        }
        return bestCount.first;


    }

    vector<vector<pair<int,int>>> adjL(int n, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            int wt = edges[i][2];

            adj[src].push_back({dest,wt});
            adj[dest].push_back({src,wt});
        }
        return adj;
    }
};