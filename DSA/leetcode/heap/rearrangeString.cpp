//LC 767
class Solution {
public:
    // struct cmp{
    //     bool operator()(const pair<int, char>, )
    // } dont need cause default max heap behaviour needed
    string reorganizeString(string s) {
        unordered_map<char,int> map;
        for(auto &i : s){
            map[i]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto &i : map){
            pq.push({i.second, i.first});
        }

        string ans;
        if(pq.empty()){
         return "";
        }
            pair<int, char> best;
            pair<int, char> secondBest;
        while(pq.size() >= 2){
            // to update teh freq you take it out, update then push again
            //also instead of circling around take a best and second best
            best = pq.top();
            pq.pop();
            secondBest = pq.top();
            pq.pop();
            ans.push_back(best.second);
            ans.push_back(secondBest.second);

            best.first--;
            secondBest.first--;

            if(best.first > 0) pq.push(best);
            if(secondBest.first > 0) pq.push(secondBest);
        }
        if(pq.empty()){
            return ans;
        }else{
            //pq has 1 elem left
            //check freq and can we add safely 
            if(pq.top().first > 1){
                return "";
            }else{
                ans.push_back(pq.top().second);
            }
        }
            
        return ans;
    }
};