//525

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero = 0;
        int ones = 0;
        int res = 0;

        unordered_map<int,int> f; //diff -> index

        for(int i = 0; i< nums.size(); i++){
            if(nums[i] == 0){
                zero ++;
            }else{
                ones++;
            }

            int diff = zero - ones;
            if(diff == 0){
                res = max(res, i + 1);
            }else if(f.find(diff) == f.end()){//Doesn't exist
                f[diff] = i;
            }else{
                int idx = f[diff]; //last seen in map
                int len = i - idx; //end - last seen
                res = max(res,len);
                //dont update last seen as you want the longest subarray
            }
        }
        return res;
    }
};