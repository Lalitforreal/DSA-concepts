class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();


        vector<bool> visited(n, false);
        int province = 0;
        // you just iterate over teh city 
        for(int city = 0; city < n ; city++){
            if(visited[city] == false){
                dfs(isConnected, city,visited);
                province++;
            }
        }
        return province;
    }

    void dfs(vector<vector<int>>& isConnected, int city,vector<bool>& visited ){
        visited[city] = true;
        for(int neighbour = 0 ; neighbour < isConnected.size(); neighbour++){
            if(isConnected[city][neighbour] == 1 && visited[neighbour] == false){
                dfs(isConnected, neighbour, visited);
            }
        }
        return;
    }

};