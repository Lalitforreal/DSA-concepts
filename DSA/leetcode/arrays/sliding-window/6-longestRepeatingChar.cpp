// LC - 24. Longest Repeating Character Replacement
// You are given a string s and an integer k.
//  You can choose any character of the string and
// change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0;
        int high ;
        int result = INT_MIN;
        vector<int> hash(256,0);
        int maxC;
        for(high = 0; high < s.size(); high++){
            hash[s[high]]++;
            int len = high - low + 1;
             maxC = maxCount(hash);
             int diff = len - maxC;
             while(diff > k){
                hash[s[low]]--;
                low++;
                len = high - low + 1;
                maxC = maxCount(hash);
                diff = len - maxC;
             }
                len = high - low + 1;
                result = max(result,len);
             
        }
        return result;
    }

    int maxCount(vector<int> hash){
        int maxC = 0;
        for(int i = 0; i < 256; i++){
            maxC = max(maxC,hash[i]);
        }
        return maxC;
    }
};