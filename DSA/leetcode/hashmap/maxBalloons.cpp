//LC 1189

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> have;
        unordered_map<char, int> need;

        for(int i = 0; i < text.size(); i++){
            have[text[i]]++;
        }

        string b = "balloon";
        for(int i = 0; i < b.size(); i++){
            need[b[i]]++;
        }

        int result = INT_MAX;

        for(auto i : need){
            char c = i.first;
            int currNeed = i.second;
            int currHave = have[c];

            int occ_Count = currHave / currNeed;

            result = min(result, occ_Count);
        }
        return result;
    }
};