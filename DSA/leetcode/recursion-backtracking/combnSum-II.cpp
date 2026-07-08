//lc 40
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.
// Example 1
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int idx = 0;
        int sum = 0;
        sort(candidates.begin(),candidates.end()); //sort for duplicate handling
        backtrack(candidates,idx, ans, temp,sum, target);
        return ans;
    }

    void backtrack(vector<int>& candidates,int idx, vector<vector<int>>& ans, vector<int>& temp, int sum, int target){
        if(sum == target){
            ans.push_back(temp);
            return;
        }

        if(idx >= candidates.size()) return; //very imp as when you reach teh end of any branch horizontally this will help you return to teh last return of funciton

        if(sum + candidates[idx] <= target){
            sum += candidates[idx];
            temp.push_back(candidates[idx]);

            backtrack(candidates, idx + 1, ans,temp,sum,target);
            sum -= candidates[idx];
            temp.pop_back();
        }
 
        int next = idx + 1;
        while(next < candidates.size() && candidates[next] == candidates[idx]){
            next++;
        }//skip same branch 

        backtrack(candidates,next, ans,temp,sum,target);
        return;

    }
};