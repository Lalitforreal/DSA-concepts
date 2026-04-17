//LC402

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;


        for(int i = 0; i < num.size() ; i++){
            while(!st.empty() && st.top() > num[i] && k > 0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

            while(!st.empty() && k > 0){
                st.pop();
                k--;
            }
            if(st.empty()){
                return "0";
            }

            //now create the string ans + make sure the starting 0 are not present in cases like 00100 return 100 
            string ans = "";
            while(!st.empty()){
                //use pushback for optimal solution
                ans.push_back(st.top());
                st.pop();
            }

            reverse(ans.begin(), ans.end());

            // remove leading zeros or if 10 -> 0 so return 0
            int i = 0;
            while(i < ans.size() && ans[i] == '0') i++;

            ans = ans.substr(i);

            return ans.empty() ? "0" : ans;

    }
};