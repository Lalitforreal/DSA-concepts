class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;
        for(int i = 0; i < n ; i++){
            vector<int> t(m, INT_MAX);
            res.push_back(t);
        }

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq; //min heap 
        vector<int> x = {-1,1,0,0};
        vector<int> y = {0,0,-1,1};

        pq.push({0, {0,0}});
        res[0][0] = 0;
        int newWt = 0;

        while(!pq.empty()){
            pair<int, pair<int,int>> curr = pq.top();
            pq.pop();
            int dist = curr.first ;
            int row = curr.second.first;
            int col = curr.second.second;

            if(dist > res[row][col]){
                continue; //cant be a better path
            }
            for(int k = 0; k < 4; k++){
                int r = row + x[k];
                int c = col + y[k];
                if(!isValid(r,c, heights.size(), heights[0].size())){
                    continue;
                }

                int absDiff = abs(heights[row][col] - heights[r][c]);
                newWt = max(dist, absDiff); //imp

                if(newWt < res[r][c]){ //if changed 
                    res[r][c] = newWt;
                    pq.push({newWt, {r,c}});
                }

            }
        }
        return res[n-1][m-1];


    }
    bool isValid(int i , int j , int n , int m){
        if(i < 0 || i >= n || j < 0 || j >= m){
            return false;
        }
        return true;
    }

};