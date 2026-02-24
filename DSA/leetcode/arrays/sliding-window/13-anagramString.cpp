// 438. Find All Anagrams in a String

// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int high = 0;
        int low =0;
        vector<int> have(256,0);
        vector<int> needed(256,0);
        vector<int> ans;

        for(int i =0; i < p.size(); i++){
            needed[p[i]]++;
        }

        for(high; high < s.size(); high++){
            have[s[high]]++;
            int len = high - low + 1;
            while(len > p.size()){
                have[s[low]]--;
                low++;
                len = high - low + 1;
            }

            if(len == p.size() && isRight(have,needed)){
                ans.push_back(low);
                continue;
            }

        }
        return ans;
    }

    bool isRight(const vector<int>& have,const vector<int>& needed){
        for(int i =0; i<256; i++){
            if(have[i]!=needed[i]){
                return false;
            }
        }
        return true; //if a and b both freq is 1
    }
};