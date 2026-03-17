//LC 1209

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i = 0; i < s.size(); i++){
            if(!st.empty() && st.top().first == s[i]){
                st.top().second++;
            }else{
                st.push({s[i],1});
            }

            if(st.top().second == k){
                st.pop();
            }
        }
        string res = "";
        while(!st.empty()){
            char c = st.top().first;
            int count = st.top().second;
            st.pop(); //imp

            for(int i = 0 ; i < count;i++){
                res.push_back(c);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};