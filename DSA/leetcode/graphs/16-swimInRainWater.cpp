class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //time is the min level req to rach that spot

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res;
        for(int i = 0; i < n ; i++){
            vector<int> t(m, INT_MAX);
            res.push_back(t);
        }

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq; //min heap 
        vector<int> x = {-1,1,0,0};
        vector<int> y = {0,0,-1,1};

        pq.push( {grid[0][0] , {0,0}}); //time,{row,col}
        res[0][0] = grid[0][0]; //you need to be at a certain level
        int newTime = INT_MIN;

        while(!pq.empty()){
            pair<int,pair<int,int>> curr = pq.top();
            pq.pop();
            int time = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;
            if(time > res[row][col]) continue;

            for(int k = 0; k< 4; k++){
                int r = row + x[k];
                int c = col + y[k];
                if(!isValid(r,c,n,m)) continue;

                newTime = max(time, grid[r][c]);
                if(newTime < res[r][c]){
                    res[r][c] = newTime;
                    pq.push({newTime, {r,c}});
                }
            }
        }
        return res[n-1][n-1];

    }

    bool isValid(int i , int j , int n , int m){
        if(i < 0 || i >= n || j < 0 || j >= m){
            return false;
        }
        return true;
    }

};