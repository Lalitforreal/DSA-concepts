//1749

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        //yaha minSum and maxSUM nikalke abs nikalo and check karo kaunsa abs bada and return cause bohot hi chota mile to hbhi achi baat hai otherwise positive toh hai hi
        //these are my bestends
        int minSum = nums[0];
        int maxSum = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int v1 = minSum + nums[i];
            int v2 = maxSum + nums[i];
            int v3 = nums[i];
            minSum = min(v3, min(v1,v2));
            maxSum = max(v3, max(v1,v2));

            int absMin = abs(minSum);
            int absMax = abs(maxSum);

            ans = max(ans, max(absMin,absMax));
        }
        return abs(ans);
    }
};