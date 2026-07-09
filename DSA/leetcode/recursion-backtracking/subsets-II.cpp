//LC-90
//Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.
// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:
// Input: nums = [0]
// Output: [[],[0]]


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int idx = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
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

        //dont take + duplicate handling ->sort arr first
        int next = idx+1;
        while(next < nums.size() && nums[idx] == nums[next] ){
            // temp.push_back(nums[next]);
            next++;
        }
        backtrack(next, nums, ans, temp);
        return;
        
    }
};