class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int,int>>> pq;//max heap

        for(auto i : arr){
            int diff = abs(i - x);
            if(pq.size() < k){
                pq.push({diff, i});
            }else{
                if(diff > pq.top().first||
                    diff == pq.top().first && i > pq.top().second){
                        continue;
                }
                pq.pop();
                pq.push({diff, i});
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};