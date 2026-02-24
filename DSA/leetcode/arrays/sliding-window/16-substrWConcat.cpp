//LC 30 HARD


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int low = 0;
        int word_len = words[0].size();
        int window_len = word_len * words.size();
        unordered_map<string,int> need;

        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            need[words[i]]++;
        }

        //For xxfoobarbar here the valid word starts at 2nd index, then 5th index etc hence offset = 1 -> 0,3,6,9 / 2-> 1,4,7,10 / 3 -> 2,4,8,11..

        for(int offset = 0; offset < word_len; offset++){
            //offset 0 -> "xxf","oob","arb" GARBAGE chunks
            //offset 2 ->correct so it will run till word_len and give the correct ans

            int low = offset;
            int count = 0;
            unordered_map<string,int> have;

            //wordlen ke steps me move
            for(int high = offset; high + word_len <= s.size(); high+= word_len){ 
                //now loop in the
                string chunk = s.substr(high, word_len);

                if(need.find(chunk) == need.end()){
                    have.clear();
                    count = 0;
                    low = high + word_len; //skip word
                    continue;
                }else{
                    have[chunk]++;
                    count++;
                }
                
                
                while(have[chunk] > need[chunk]){
                    string leftChunk = s.substr(low,word_len);
                    have[leftChunk]--;
                    low+=word_len;
                    count--;
                }

                if(count == words.size()){
                    ans.push_back(low);
                }
            }


        }
        return ans;
    }
};

