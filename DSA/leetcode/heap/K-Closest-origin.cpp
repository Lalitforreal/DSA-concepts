//LC 973

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // take a pq of pair<vector<int>, distance from origin>
        // insert till k 
        // then maintain a max heap 
        // if (pq.top.first[1] < dist  ) continue
       
        priority_queue<pair<int, vector<int>> ,  vector<pair<int, vector<int>>>> pq;
        // the first is what you store , and the second is how the container is
        for(auto i : points){
            // int distance = sqrt((i[0] * i[0]) + (i[1] * i[1])); instead of this 
            // sqrt is slower, floating point 
            int distance = (i[0] * i[0]) + (i[1] * i[1]);
            if(pq.size() < k){
                pq.push({distance, i});
            }else{
                if(pq.top().first <= distance){
                    continue;
                }
                pq.pop();
                pq.push({distance,i});
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};