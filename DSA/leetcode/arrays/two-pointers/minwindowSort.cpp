class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st; // idx
        int left = INT_MAX;
        int right = nums.size();
        int val;
        int maxVal = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                val = st.top();
                maxVal = max(nums[val], maxVal);
                left = min(left,val);
                st.pop();
            }
            //rightmost boundary for case like 1,3,2,2,2,4,5 the right will be updated when compared against 3
                if(nums[i] < maxVal){
                    right = i;
                }

            st.push(i);
        }
        return (left == INT_MAX)? 0 : right - left + 1;
    }

};