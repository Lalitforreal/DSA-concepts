// 1358. Number of Substrings Containing All Three Characters

// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

class Solution {
public:
    int numberOfSubstrings(string s) {

        vector<int> have(256,0);

        int low = 0;
        int high ;
        int count = 0;
        // string n = "abc";
        // for(int i = 0; i < n.size(); i++){
        //     needed[n[i]]++;
        // }

        for(high = 0 ; high< s.size(); high++){
            have[s[high]]++;
            int len = high - low + 1;
            //or use the isRight func
            while( have['a']>0 && have['b']>0 && have['c']>0){
                have[s[low]]--;
                low++;
                len = high - low + 1;
            }

            count+=low;
        }
        return count;
    }

    // bool isRight(const vector<int>& have ,const vector<int>& needed){
    //     for(int i = 0; i<256; i++){
    //         if(have[i] < needed[i]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
};