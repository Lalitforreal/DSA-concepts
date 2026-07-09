//LC-78 Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.
// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:
// Input: nums = [0]
// Output: [[],[0]]


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int idx = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(idx, nums, ans, temp);
        return ans;
    }

    void backtrack(int idx, vector<int>& nums,vector<vector<int>>& ans, vector<int>& temp){
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }
        //take 
        temp.push_back(nums[idx]);
        backtrack(idx+1, nums, ans, temp);
        temp.pop_back();

        //dont take
        backtrack(idx + 1, nums, ans, temp);
        return;
        
    }
};
