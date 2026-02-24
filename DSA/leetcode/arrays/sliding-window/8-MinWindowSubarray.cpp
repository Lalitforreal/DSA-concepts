// LC-76. HARD - 
// Minimum Window Substring
// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique



class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> have(256,0);
        vector<int> needed(256,0);

        if(s.size() < t.size()){
            return "";
        }

        //make needed hash
        for(int i = 0; i<t.size(); i++){
            needed[t[i]]++;
        }
        int low = 0;
        int high;
        int result = INT_MAX;
        int start = -1;

        for(high =0 ; high < s.size(); high++){
            have[s[high]]++;
            while(isRight(have,needed)){
                int len = high - low + 1;
                if(result > len){
                    result = len;
                    start = low; // this will be the starting point of the substr everytime 
                }
                have[s[low]]--;
                low++;
            }
        }
        return (result == INT_MAX)?"" : s.substr(start,result);
    }

    bool isRight(const vector<int>& have ,const vector<int>& needed){
        for(int i = 0; i<256; i++){
            if(have[i] < needed[i]){
                return false;
            }
        }
        return true;
    }
};