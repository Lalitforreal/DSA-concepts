class Solution {
public:

struct cmp{
    bool operator()(const pair<string, int>& a, const pair<string, int>& b){
        if(a.second != b.second){
            return a.second > b.second;
        }
        //lexographically work
        return a.first < b.first; //smaller first
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue< pair<string,int>, vector<pair<string,int>>, cmp> pq;
        unordered_map<string, int> map;

        for(int i = 0 ; i < words.size(); i++){
            map[words[i]]++;
        }

        for(auto i : map){
            if(pq.size() < k){
                pq.push({i.first, i.second});
            }else{
                if(i.second < pq.top().second || i.second == pq.top().second && i.first > pq.top().first){
                    continue;
                }else{
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        vector<pair<string,int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }

        sort(ans.begin(),ans.end(), [](auto &a, auto &b){
            if(a.second != b.second){
                return a.second > b.second;
            }
            return a.first < b.first;
        });

        vector<string> final;
        for(auto &i : ans){
            final.push_back(i.first);
        }
        return final;


    }
};