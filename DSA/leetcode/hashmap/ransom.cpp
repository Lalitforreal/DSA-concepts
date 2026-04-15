//LC 383

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mag(256,0);
        vector<int> rans(256,0);

        for(int i = 0; i < ransomNote.size(); i++){
            rans[ransomNote[i]]++;
        }

        for(int i = 0; i < magazine.size(); i++){
            mag[magazine[i]]++;
        }



        for(int i = 0; i < 256; i++){
            if(mag[i] < rans[i]){
                return false;
            }   
        }
        return true;
    }
};