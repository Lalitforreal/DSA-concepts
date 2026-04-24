class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>& a, const pair<int,int>& b){
            return a.second > b.second; //min heap
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int,int>>,cmp> pq;
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }


        for(auto i : map){
            if(pq.size() < k){
                pq.push({i.first,i.second});
            }else{
                if(i.second <= pq.top().second){
                    continue;
                }
                pq.pop();
                pq.push({i.first,i.second});
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};