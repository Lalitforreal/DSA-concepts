//lc 1567


class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int posLen = 0;
        int negLen = 0;
        int maxLen = posLen;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                posLen += 1;
                negLen = (negLen > 0)? negLen + 1 : 0;
            }
            else if ( nums[i] < 0){
                //swap
                int newPos = (negLen > 0)? negLen + 1 : 0;
                int newNeg = posLen + 1;
                posLen = newPos;
                negLen = newNeg;
            }else{
                //if 0 just count reset
                posLen = 0;
                negLen = 0;
            }
            
            maxLen = max(maxLen, posLen);
        }
        return maxLen;
    }
};