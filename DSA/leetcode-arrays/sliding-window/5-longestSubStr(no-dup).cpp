
//LC 3

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int high ;
        int size = s.size();
        unordered_map<char,int> f;
        int result = INT_MIN;

        for(high =0 ; high < s.size(); high++){

            // yaha na hashmap me jo bhi info hai usko k maanlo and len ko store karlo
            f[s[high]]++;
            int len = high - low + 1;
            while(f.size() <  len ){
                f[s[low]]--;
                if(f[s[low]] == 0){
                    f.erase(s[low]);
                }
                low++;
                //recalculate length 
                len = high - low + 1;
            }

            if(f.size() == len ){
                len = high - low + 1;
                result = max(result,len);
            }
        }
        return (result == INT_MIN)? 0 : result;
    }
};