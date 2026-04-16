
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for(int i = 0; i < n; i++){
            int curr = asteroids[i];
            bool destroyed = false; 

            while(!st.empty() && st.top() > 0 && curr < 0){
                //collison only possible when - + 
                //now choose what will happen 
                if(abs(st.top()) == abs(curr)){
                    //both pop and dont add curr
                    st.pop();
                    destroyed = true; //Did the (curr) die during collisions?
                    break; //Stop the collision loop
                }else if(abs(st.top()) > abs(curr)){
                    destroyed = true;
                    break;
                }else{
                    st.pop();
                }
            }

            if(!destroyed){ //if curr not destroyed in teh process you push
                st.push(curr);
            }
        }
        //now form the array with the stack
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};