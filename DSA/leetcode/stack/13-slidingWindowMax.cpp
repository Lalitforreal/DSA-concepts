//lc 239


//brute force
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> res;

        for(int i = 0; i < k; i++){
            ms.insert(nums[i]);
        }
        res.push_back(*ms.rbegin());//max element

        for(int i = k ; i < nums.size(); i++){
            //nums[i] is teh next element waitng to get into window
            ms.erase(ms.find(nums[i - k]));

            ms.insert(nums[i]);

            res.push_back(*ms.rbegin());
        }
        return res;
    }
};

//optimized using deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            if(!dq.empty() && nums[dq.front()] <= i - k  ){
                dq.pop_front();
            }
            //monotonicicty 
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};