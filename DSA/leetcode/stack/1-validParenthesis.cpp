class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                //opening brackets push directly
                st.push(s[i]);
            }else{
                //if stack is empty return false;
                if(st.empty()){
                    // } is the first elem and cant be valid
                    return false;
                }
                //not starting bracket
                //valid so like think of it like a for{ if{} } if brackets are done you can check the for bracket   
                if(s[i] == ')' && st.top() == '('){
                     st.pop();
                }else if(s[i] == '}' && st.top() == '{') {
                    st.pop();
                }else if(s[i] == ']' && st.top() == '['){
                    st.pop();
                }else{
                    //{] mismatch
                    return false;
                }
            }
        }
        //outside loop check if st is empty if not empty that means some opening bracket isnt closed hence invalid
        if(!st.empty()) return false;

        return true;
    }
};