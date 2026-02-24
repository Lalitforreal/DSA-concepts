// 1248. Count Number of Nice Subarrays
// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

class Solution {
public:

    int atmostSubArray(vector<int>& nums, int k){
        int low = 0;
        int high ;
        int countFinal = 0;
        int countOdd = 0;
        for( high = 0; high < nums.size(); high++){
            if(nums[high]%2 != 0 ) countOdd++;
            while(countOdd > k){
                if(nums[low]%2 != 0){
                    countOdd--;
                }
                low++;  
            }

            if(countOdd <= k){
                countFinal+= high - low + 1;
            }
        }
        return countFinal;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostSubArray(nums, k) - atmostSubArray(nums, k -1);
    }
};