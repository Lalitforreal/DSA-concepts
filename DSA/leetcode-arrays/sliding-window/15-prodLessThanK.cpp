
// 713. Subarray Product Less Than K

// Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        long long prod = 1;
        int count = 0;

            if(k<=1){
                return 0;
            }
        for(high ; high < nums.size(); high++){
            prod*=nums[high];
            while(prod >= k){
                prod= prod/nums[low];
                low++;
            }
            if(prod < k){
                count+=high-low+1;
            }
        }
        return count;
    }
};