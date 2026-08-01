//raw
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        bool border = false;
        vector<vector<bool>> visited(n);
        for(int i = 0; i < n ; i++){
            vector<bool> t(m, false);
            visited[i] = t; //assign that vec
        }

        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0; j< m; j++){
                if(board[i][j] == 'O'){
                    dfs(board, i , j , n , m , visited,border);
                    if(border == false){
                        for(int k = 0; k < board.size(); k++){
                            for(int l = 0; l < board[0].size(); l++){
                                if(visited[k][l] == true){ //to make it valid you gotta reset teh visited every iteration
                                    //all visisted are O so change to X
                                    board[k][l] = 'X';
                                    visited[k][l] = false;
                                }
                            }
                        }
                    }else{
                        //reset visited too
                        for(int d = 0; d < visited.size(); d++){
                            for(int e = 0; e < visited[0].size();e++ ){
                                if(visited[d][e] == true){
                                    visited[d][e] =false;
                                }
                            }
                        }
                    }   
                    //make the border true again for next island
                    border = false;
                    //reset visited to falsee 
                }
            }
        }
    }
    vector<int> x = {-1, 1, 0 , 0};
    vector<int> y = {0,0,-1, 1};

    bool isValid(int i , int j , int n , int m){
        if(i < 0 || i >= n || j < 0 || j >= m){
            return false;
        }
        return true;
    }


    void dfs(vector<vector<char>>& board, int i , int j , int n , int m ,vector<vector<bool>>& visited , bool& border){
        visited[i][j] = true;
        //check if current on border if yes just make the island validity false
        //i - row and j - col
        if(i == 0 || i == n-1 || j == 0 || j == m -1){
            //if border
            border = true;
        }
        for(int k = 0; k < 4 ; k++ ){
            int row = i + x[k];
            int col = j + y[k];
            if(isValid(row,col,n,m) && board[row][col] == 'O' && visited[row][col] == false){
                dfs(board ,row,col, n,m, visited, border);
            }
        }
    }

};



//optimized
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        // both border rows if 0 dfs
        //both border col if 0 dfs

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){ //first row
                dfs(board, i, 0, n,m);
            }
            if(board[i][m-1] == 'O'){ //last col
                dfs(board,i, m-1, n,m);
            }
        }

        for(int j = 0 ; j < m; j++){
            if(board[0][j]== 'O'){
                dfs(board, 0,j, n,m);

            }
            if(board[n-1][j] == 'O'){
                dfs(board, n-1, j, n,m);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X'; //surrounded
                }
            }
        }

    }

    //goal of border dfs is to find all border invalid Os and island and then just iterate and flip the 0 -> X and # to O
    void dfs(vector<vector<char>>& board, int i , int j , int n , int m ){
        //if not valid or curr != 0 jus return 
        if( i < 0 || j < 0 || i >=n || j >= m || board[i][j] != 'O' ){
            return;
        }
        // mark curr # (border)
        board[i][j] = '#'; //border

        // now all 4 direction dfs
        dfs(board,i-1 ,j ,n,m);
        dfs(board,i+1 ,j ,n,m);
        dfs(board,i , j -1 ,n,m);
        dfs(board,i ,j+1 ,n,m);
    }

};