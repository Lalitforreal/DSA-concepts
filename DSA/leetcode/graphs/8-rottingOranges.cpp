//multi source bfs
class Solution {
public:
    vector<int> x = {0 , 0 , -1, 1};
    vector<int> y = {-1, 1, 0,0};
        int fresh = 0;
        int time = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        //traverse once, keep a fresh count, 
        //push all the rotten ones in the queue already,
        //then perform dfs 
        queue<pair<int,int>> q; //keep index stores
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});//rotten
                }else if(grid[i][j] == 1){
                    fresh++;
                }else{
                    continue;
                }
            }
        }

        //traversal done you have fresh count when passed as ref
        bfs(grid,q, fresh);


        if(fresh > 0){
            return -1;
        }else{
            return time;
        }
    }

    void bfs(vector<vector<int>>& grid,queue<pair<int,int>>& q, int& fresh){
        int m =  grid.size();
        int n = grid[0].size();
        while(!q.empty() && fresh > 0){
            time++;
            int size = q.size(); //parallalism of rotting
            while(size > 0){
                pair<int,int> curr = q.front();
                q.pop();
                size--;
                for(int k = 0 ; k < 4; k++){
                    int row = curr.first + x[k];
                    int col = curr.second + y[k];
                    //up down left right traversal
                    if(isValid(row, col ,m,n) && grid[row][col] == 1){
                        fresh--;
                        grid[row][col] = 0;
                        q.push({row,col});
                    }
                }
            }
        }
    }

    bool isValid(int i , int j , int m , int n){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return false;
        }
        return true;
    }
};