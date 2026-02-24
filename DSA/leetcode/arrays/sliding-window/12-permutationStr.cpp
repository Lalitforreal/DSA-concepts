// 567. Permutation in String
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int low = 0;
        int high = 0;
        vector<int> have(256,0);
        vector<int> needed(256,0);

        for(int i = 0; i < s1.size(); i++){
            needed[s1[i]]++;
        }
        
        for(high ; high < s2.size(); high++){
            have[s2[high]]++;
            int len = high - low + 1;
            while( len > s1.size()){
                have[s2[low]]--;
                low++;
                len = high - low + 1;
            }

            if(len == s1.size() && isRight(have,needed)){
                return true;
            }
        }
        return false;
    }

    bool isRight(const vector<int>& have,const vector<int>& needed){
        for(int i = 0; i < 256 ; i++){
            if(have[i] != needed[i]){ // everything except members of s1 will always be false so if its equal hence freq same;
                return false;
            }
        }
        return true;
    }
};