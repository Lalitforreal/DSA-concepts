class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int result = INT_MIN;
        int maxCount;
        vector<int> hash(2,0);

        for(high; high < nums.size(); high++){
            hash[nums[high]]++;
            int len = high - low + 1;
            int diff = len - hash[1];
            while(diff > k){
                hash[nums[low]]--;
                low++;
                len = high - low + 1;
                diff = len - hash[1];
            }
            if(diff <= k){
                int len = high - low  +1;
                result = max(result,len);
            }
        }
        return result;
    }
};