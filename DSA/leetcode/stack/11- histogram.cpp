//LC 84
//brute force
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {

        //brute force
        
        stack<int> st;
        int n = h.size();
        vector<int> nse(n), pse(n);
        findnse(nse,h,n);
        findpsee(pse,h,n);

        int maxi = 0;

        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi, h[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;
    }

    void findnse(vector<int>& nse, vector<int>& nums, int n){
        stack <int> st; //store index
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && nums[st.top()] > nums[i] ){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }else{
                nse[i] = st.top();
            }
            st.push(i);
        }
    }
    void findpsee(vector<int>& psee, vector<int>& nums, int n){
        stack <int> st; //store index
        for(int i = 0 ; i <n ; i++){
            while(!st.empty() && nums[st.top()] >= nums[i] ){
                st.pop();
            }
            if(st.empty()){
                psee[i] = -1;
            }else{
                psee[i] = st.top();
            }
            st.push(i);
        }
    }
};

//optimal
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int n = h.size();
        int maxi = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && h[st.top()] > h[i]){
                int elem = h[st.top()]; //find pse and nse for this elem
                st.pop();
                int pse = st.empty()? -1 : st.top();
                int nse = i;
                maxi = max(maxi, elem * (nse - pse - 1));
            }
            st.push(i);
        }
        //after the forloop
        while(!st.empty()){
            int elem = h[st.top()];
            st.pop();
            int pse = st.empty()?-1 : st.top();
            maxi = max(maxi, elem * (n - pse - 1));
        }
        return maxi;
    }
};