class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);

        //given rooms is the adj list itself
        //start form 0 always so no loop
        dfs(rooms, 0, visited); 

        for(auto i : visited){
            if( i == false){
                return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<int>>& rooms, int room,vector<bool>& visited ){
        visited[room] = true;
        //iterate inside the room to see neighbours
        for(int i = 0 ; i < rooms[room].size() ; i++){
            int neighbour = rooms[room][i];
            if(visited[neighbour] == false){
                dfs(rooms, neighbour, visited);
            }
        }
    }
};