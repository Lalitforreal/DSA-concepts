class Solution {
public:

    struct cmp{
        bool operator()(const pair<int,int>& a, const pair<int,int>& b){
            return a > b; //min heap as if cmp true - b priority
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj = adjL(times,n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        vector<int> dist(n + 1, INT_MAX); //1 based 
        // pq has DIST from src, node
        pq.push({0, k}); //k to all nodes and give min time hence max of the result arr
        //update dist 
        dist[k] = 0;
        while(!pq.empty()){
            pair<int,int> node = pq.top();
            pq.pop();
            int d = node.first;
            int currNode = node.second;
            for(int i = 0; i < adj[currNode].size(); i++){
                pair<int,int> neighbour = adj[currNode][i];
                if(d + neighbour.second < dist[neighbour.first]){
                    pq.push({d + neighbour.second , neighbour.first});
                    dist[neighbour.first] = d + neighbour.second;
                }
            }

        }
        int maxAns = -1;
        bool reached = true;
        //dist = time taken so find max
        for(int i = 1; i < dist.size(); i++){
            if(maxAns < dist[i] && dist[i]!= INT_MAX){
                maxAns = dist[i];
            }
            if(dist[i] == INT_MAX){
                reached = false;
            }
        }

        return (reached == true)? maxAns : -1;
    }

    vector<vector<pair<int,int>>> adjL(vector<vector<int>>& times,int n){
        vector<vector<pair<int,int>>> adj(n+1); //1 based idx
        for(int i = 0; i < times.size(); i++){
            vector<int> edge = times[i];
            int src = edge[0];
            int dest = edge[1];
            int wt = edge[2];
            //push pair of neighbour,weight in src vector
            adj[src].push_back({dest, wt});
        }
        return adj;
    }
};