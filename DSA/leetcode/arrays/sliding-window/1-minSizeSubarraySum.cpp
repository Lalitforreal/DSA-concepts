class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high = 0;
        int result = INT_MAX; //cuz min nikalna hai if max -> INT_min lena
        int sum = 0;

        while(high<nums.size()){
            sum = sum + nums[high];
            while(sum >= target){
                int len = high - low + 1 ; //+1 for index 
                result = min(result,len);
                sum = sum - nums[low];
                low++;
            }
            high++;
        }

        return(result == INT_MAX)? 0: result;
    }
};