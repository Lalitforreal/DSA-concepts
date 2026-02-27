class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int bestending = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++ ){
            //its either the sum of prev and curr or just current
            int firstOpt = bestending + nums[i];
            int secondOpt = nums[i];
            bestending = max(firstOpt,secondOpt);
            ans = max(ans,bestending);
        }
        return ans;
    }
};