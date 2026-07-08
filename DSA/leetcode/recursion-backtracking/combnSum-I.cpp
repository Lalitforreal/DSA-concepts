//LC 39
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:
// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:
// Input: candidates = [2], target = 1
// Output: []


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int idx = 0;
        int sum = 0;
        backtrack(candidates,idx, ans, temp,sum, target);
        return ans;
    }

    void backtrack(vector<int>& candidates,int idx, vector<vector<int>>& ans, vector<int>& temp, int sum, int target){
            if(sum == target){
                ans.push_back(temp);
                return;
            }

            if(idx < candidates.size() && sum + candidates[idx] <= target){
                sum+= candidates[idx];
                temp.push_back(candidates[idx]);
                backtrack(candidates,idx, ans, temp, sum, target); //dont move
                sum-= candidates[idx]; //baktrack very imporatnt as this will remove the elem
                temp.pop_back();
            }
            if(idx < candidates.size()-1 ){
                backtrack(candidates,idx+1, ans,temp,sum,target); // 2+2+2 will be 2+2+3 when the last return statement is done

                 //nothing that this branch did so why undo
               
            }
            return;
    }
};