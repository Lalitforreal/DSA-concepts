//Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        int idx = 0;
        backtrack(idx,s,temp,ans);
        return ans;

    }

    void backtrack(int idx, string& s,vector<string>& temp, vector<vector<string>>& ans ){
        if(idx == s.size() ){
            ans.push_back(temp);
            return;
        }

        for(int end = idx; end < s.size(); end++){
            string curr = s.substr(idx, end- idx + 1);
            if(isPalindrome(curr)){
                temp.push_back(curr); //partition done now next partition starts after this partition ends
                backtrack(end+1,s,temp,ans );
                temp.pop_back();
            }
        }
        return;

    }

    bool isPalindrome(string& s){
        int st = 0;
        int e = s.size()-1;
        bool pal = false;
        for(int i = st ; i < s.size(); i++){
            if(s[st] != s[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
};