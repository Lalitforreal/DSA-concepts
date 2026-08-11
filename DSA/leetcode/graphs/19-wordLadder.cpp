class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> map;
        for(int i = 0; i < wordList.size();i++){
            map[wordList[i]] = 1;
        }
        if(map.find(beginWord) == map.end()){ //not present
            map[beginWord] = 1;
        }
        if(map.find(endWord) == map.end()){//if nedWord not in list return 0
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        map.erase(beginWord);

        while(!q.empty()){
            pair<string, int> curr = q.front();
            q.pop();
            string s = curr.first;
            int val = curr.second;
            if(s == endWord) return val;

            //if not change each char 
            for(int i = 0; i < s.size(); i++){
                char c = s[i];
                for(int j = 97; j <= 122; j++){
                    //ascii value of a to z
                    if(c == j) continue;
                    s[i] = j;
                    if(map.find(s) != map.end()){
                        //if present 
                        q.push({s, val + 1});
                        map.erase(s);
                    }
                s[i] = c; //original so you can check next
                }
            }
        }

        return 0;


    }
};