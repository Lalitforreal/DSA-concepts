//lc 22
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        string temp = "";
        vector<string> ans;
        backtrack( open,  close,  temp, ans, n);
        return ans;
    }

    //make sure you pass ans by reference as if you dont you are returning void so it will be updated lcoally int he function itself not the main one
    void backtrack(int open, int close, string& temp, vector<string>& ans, int n){
        if(open == n && close == n){
            ans.push_back(temp);
            return;
        }

        if(open < n){
            temp.push_back('(');
            backtrack(open + 1,close,temp,ans,n); //chose teh open one and wander all possibilities
            temp.pop_back(); //reverse like it never happened so backtrack here
        }
        //only valid after chooseing all open then reversing your decision
        if(close < open){
            temp.push_back(')');
            backtrack(open,close + 1, temp, ans, n);
            temp.pop_back();
        }
        return;
    }

};