// 992. HARD
// Subarrays with K Different Integers

// Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array.


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int low = 0;
        int high ;
        unordered_map<int, int> f1;
        unordered_map<int, int> f2;
        int countK = 0;
        int countKm1 = 0;

        //for k
        for(high= 0; high<nums.size();high++){
            f1[nums[high]]++;
            while(f1.size() > k){
                f1[nums[low]]--;
                if(f1[nums[low]]==0){
                    f1.erase(nums[low]);
                }
                low++;
            }
                if(f1.size() <= k){
                    countK+= high - low + 1;
                }
        }

        low = 0;
        //for k - 1
        for(high= 0; high<nums.size();high++){
            f2[nums[high]]++;
            while(f2.size() > k - 1){
                f2[nums[low]]--;
                if(f2[nums[low]]==0){
                    f2.erase(nums[low]);
                }
                low++;
            }
                if(f2.size() <= k - 1){
                    countKm1 += high - low + 1;
                }
        }

        return countK-countKm1;

    }
};