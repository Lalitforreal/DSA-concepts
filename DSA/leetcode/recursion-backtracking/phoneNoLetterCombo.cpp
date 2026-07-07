// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = "2"
// Output: ["a","b","c"]

//LC 17
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        int idx = 0;
        vector<string> ans;
        string temp = "";
        unordered_map<char, string> map = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        backtrack(idx, digits, temp, ans, map);
        return ans;
    }

    void backtrack(int idx,string& digits,string&temp,vector<string>& ans, unordered_map<char,string>& map){
        if(idx == digits.size()){
            ans.push_back(temp);
            return; //base
        }

        string choice = map[digits[idx]];
        for(int j = 0; j < choice.size(); j++){
            temp.push_back(choice[j]);
            backtrack(idx+ 1, digits,temp,ans,map);
            temp.pop_back();
        }
        return;
    }

};