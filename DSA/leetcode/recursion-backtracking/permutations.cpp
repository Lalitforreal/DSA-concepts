// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]

//LC 46
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int idx = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtrack(idx, nums, ans, temp, used);
        return ans;
    }

    void backtrack(int idx, vector<int>& nums,vector<vector<int>>& ans, vector<int>& temp, vector<bool>& used){
        //base case
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }

        //now you gotta make sure you're not repeating elem so use the bool array 
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true) continue;
            //make sure you change the state
            used[i] = true;
            temp.push_back(nums[i]);
            //chosen now move ahead using recursion
            backtrack(idx + 1, nums,ans,temp,used);
            //when done with all possibilities
            //backtrack
            temp.pop_back();
            used[i] = false;
        }
        return;
    }
};