
    //bellman ford

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> res(n, INT_MAX);
        vector<int> temp = res;
        res[src] = 0;
        temp[src]=0;
        for(int i = 0; i < k + 1 ; i++){ //instead of n-1 
        //just k go till k and see for yourself
            for(int j = 0; j < flights.size(); j++){
                //inside update temp for avoiding chain reaction
                int s = flights[j][0];
                int dest = flights[j][1];
                int wt = flights[j][2];
                if(res[s]!= INT_MAX && res[s] + wt < temp[dest]){ //compare with original res[s] + wt before relaxation all rlx happens in temp so no chain reaciton
                    //k 
                    temp[dest] = res[s] + wt;
                }
                
            }
            res = temp;
        }
        return (res[dst] == INT_MAX)? -1 : res[dst];
    }
};