class Solution {
public:
    vector<int> x = {-1, 1, 0 , 0};
    vector<int> y = {0,0,-1, 1};

    bool isValid(int i , int j , int n , int m){
        if(i < 0 || i >= n || j < 0 || j >= m){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char>>& grid, int i , int j , int n , int m ,vector<vector<bool>>& visited ){
        visited[i][j] = true;
        //explore
        for(int k = 0; k < 4; k++){
            int row = i + x[k];
            int col = j + y[k];

            if(isValid(row,col, n,m) && grid[row][col] == '1' && visited[row][col] == false){
                dfs(grid, row, col, n, m , visited);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        int i, j;
        vector<vector<bool>> visited(n);
        for(int i = 0; i < n ; i++){
            vector<bool> t(m, false);
            visited[i] = t; //assign that vec
        }

        for(i = 0 ; i < n ; i++){
            for(j = 0; j < m; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    dfs(grid, i, j , n , m, visited);
                    res++;
                }
            }
        }
        return res;
    }
};