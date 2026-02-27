class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++){
            //options
            int v1 = maxEnding * nums[i];
            int v2 = minEnding * nums[i];
            int v3 = nums[i];

            maxEnding = max(v3, max(v1,v2));
            minEnding = min(v3, min(v1,v2));

            ans = max(ans, max(maxEnding, minEnding));
        }
        return ans;
    }
};