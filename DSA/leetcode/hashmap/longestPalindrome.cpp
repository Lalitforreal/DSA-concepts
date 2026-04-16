class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        for(int i = 0 ; i < s.size(); i++){
            freq[s[i]]++;
        }
        int result = 0;
        bool odd = false;

        for(auto i : freq){
            if(i.second % 2 == 0){//even
                int val = i.second;
                result += val;
            }else{
                odd = true;
            }
        }

        if(odd == false){
            return result;
        }
        //if odd

        for(auto i : freq){
            int val = i.second;
            if(val % 2 == 1){//odd
                result += val - 1;
            }
        }
        return result + 1; //odd wala in middle
    }
};