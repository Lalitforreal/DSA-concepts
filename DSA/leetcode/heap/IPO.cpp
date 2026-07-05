//lc 502

class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, int>& a,const pair<int, int>& b){
            if(a.first!= b.first){
                //small capital first
                return a.first > b.first;
            }
            //max profit first
            return a.second < b.second;
        }
    };

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int >, vector<pair<int, int>>, cmp> pq1;//capital and profit
        priority_queue<int> pq2; //max heap for profit

        for(int i = 0; i < profits.size(); i++){
            pq1.push({capital[i],profits[i]});
        }

        while( k > 0){
            //jabtak exhause nahi hota and its valid 
            while( !pq1.empty() && pq1.top().first <= w){
                pq2.push(pq1.top().second);
                pq1.pop(); 
            } 
            //you create a heap of max profit from the valids and then you choose the one

            if(!pq2.empty()){
                w+=pq2.top();
                pq2.pop();
                k--; //added to capital so yeah 
            }else{
                return w;
            }

        }
        return w;
    }
};