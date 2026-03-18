class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;

        stringstream ss(path); // this tokenises teh string
        string token;

        while(getline(ss,token,'/')){//split by /
            if(token == "." || token == ""){
                continue;
            }else if(token == ".."){//st.top ko pop 
                if(!st.empty()) st.pop();
            }else{
                st.push(token);
            }
        }

        //now the order will be reversed so to handle it 
        vector<string> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }

        string ans = "";
        for(int i = temp.size()-1; i >= 0; i--){
            ans += "/" + temp[i];
        }

        if(ans.empty()) return "/";
        return ans;
    }
};