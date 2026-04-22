//LC 901

class StockSpanner {
public:
    int i;
    StockSpanner() {
        i = -1; //simulate index
    }
    stack<pair<int,int>> st; //stores val,index 
    int next(int price) {
        i++;

        while(!st.empty() && st.top().first <= price){ //pop until prev greater found or st empty=
            st.pop();

        }
        int pge = st.empty() ? -1 : st.top().second; //index of top if not empty
        int span = i -pge;
        st.push({price, i});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */