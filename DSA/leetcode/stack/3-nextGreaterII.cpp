class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st; //add indexes for duplicate prevention 

        //circular so consider like the same array back to back and start from the end
        for(int i = 2*n -1 ; i>=0; i--){
            // for index
            int idx = i%n;
            
            while(!st.empty() && nums[idx] >= nums[st.top()]){
                st.pop();
            }

            if(st.empty()){
                ans[idx] = -1;
            }else{
                ans[idx] = nums[st.top()];
            }
            st.push(idx);
        }
        return ans;
    }
};


//or
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> monoSt;
        int n = nums.size();
        //hre use index -> value 
        vector<int> ans(n,-1); //if none will have -1

        for(int i = (2*n)-1 ; i>= 0; i--){ //2 back to bcak array
            //circular array so use i%n everywhere 
            if(monoSt.empty()){
                // ans[i%n] = -1;
                monoSt.push(i%n);
            }else{
                if(nums[i%n] < nums[monoSt.top()]){
                    ans[i%n] = nums[monoSt.top()];
                    monoSt.push(i%n);
                }else{
                    while(!monoSt.empty() && nums[i%n]>= nums[monoSt.top()]){
                        monoSt.pop();
                    }//now st.top() is greater than nums and it can either be empty or not
                    if(monoSt.empty()){
                        // ans[i%n] = -1; //already -1
                        monoSt.push(i%n);
                    }else{
                        ans[i%n] = nums[monoSt.top()];
                        monoSt.push(i%n);                       
                    }
                }
            }

        }

        vector<int> res;
        for(int i = 0; i < n ; i++){
            res.push_back(ans[i]);
        }

        return res;
    }
};