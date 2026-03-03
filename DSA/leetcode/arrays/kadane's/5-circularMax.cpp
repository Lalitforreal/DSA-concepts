//LC 918

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //total sum - min sum is equal to max sum 

        int currMax = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        int currMin = nums[0];
        int totalSum = nums[0];


        for(int i = 1; i < nums.size(); i++){
            currMax = max(currMax + nums[i], nums[i]);
            maxSum = max(maxSum, currMax);

            currMin = min(currMin + nums[i], nums[i]);
            minSum = min(minSum, currMin);

            totalSum += nums[i];
        }

        int circularSum = totalSum - minSum;

        if(circularSum == 0){
            return maxSum;
        }

        int ans = max(circularSum, maxSum);
        return ans;
    }
};