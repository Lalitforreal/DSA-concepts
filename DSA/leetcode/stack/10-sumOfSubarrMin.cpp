//LC907

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> pse = prevSmallEqual(arr);
        vector<int> nse = nextSmall(arr);

        int total = 0;
        int mod = (int)(1e9 + 7);
        for(int i = 0; i < arr.size(); i++){
            int left = i - pse[i];
            int right = nse[i] - i;

            total = (total + (left * right * (long long)arr[i]))%mod;
        }
        return total;
    }

    //find nse and pse of teh whole array in a singel time
    vector<int> prevSmallEqual(vector<int>& arr){
        stack<int> st;
        vector<int> res(arr.size());
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] >= arr[i] ){ //strictly smaller when right to left
                st.pop();
            }
            if(st.empty()){
                res[i] = -1;
            }else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> nextSmall(vector<int>& arr){
        stack<int> st;
        vector<int> res(arr.size());
        for(int i = arr.size() - 1; i >=0 ; i--){
            while(!st.empty() && arr[st.top()] > arr[i] ){
                st.pop();
            }
            if(st.empty()){
                res[i] = arr.size(); //for line 13 it will result in negative if -1
            }else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }

};