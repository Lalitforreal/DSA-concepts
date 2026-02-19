// You are given a string s consisting only lowercase alphabets and an integer k.
// Your task is to find the length of the longest substring that contains exactly k distinct characters.
// Note : If no such substring exists, return -1. 

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int low = 0;
        int high;
        int result = INT_MIN;
        int size = s.size();
        unordered_map<char,int> f;
        
        for( high = 0 ; high < size; high++ ){
            f[s[high]]++;
            while(f.size()>k){
                f[s[low]]--;
                low++;
                if(f[s[low-1]] == 0){
                    f.erase(s[low-1]);
                }
            }
            if(f.size()==k){
                int len = high - low + 1;
                result = max(result, len);
            }
        }
        return (result == INT_MIN)? -1: result;
    }
};