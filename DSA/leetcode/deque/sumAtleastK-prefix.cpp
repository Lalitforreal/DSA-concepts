class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> dq; //monotonically inc queue of idx
        dq.push_back(0);
        int right = 0;
        vector<int> prefixArr(nums.size() + 1); //need a 0 in start right - left 
        //i 0 index is start of that subarr you need it
        int result = INT_MAX;
        prefixArr[0] = 0;
        //construct prefix arr
        for(int i = 0 ; i < nums.size(); i++){
            prefixArr[i + 1] = prefixArr[i] + nums[i]; //skip 0
        }

        for(int i = 0; i < nums.size() + 1; i++){ 
            while(!dq.empty() && prefixArr[i] - prefixArr[dq.front()] >= k){
                result = min(result, i - dq.front());
                dq.pop_front();
            }

            //maintain monotonicity
            while(!dq.empty() && prefixArr[i] <= prefixArr[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return (result == INT_MAX)? -1 : result;
    }
};