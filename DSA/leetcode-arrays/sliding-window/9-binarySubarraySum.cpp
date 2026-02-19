
// atmost k - atmost (k-1) = exact K.

// LC -930. Binary Subarrays With Sum
// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

class Solution {
public:

    int atmostSubArray(vector<int>& nums, int goal){
        int low = 0;
        int high ;
        int sum = 0;
        int count = 0;
        if(goal < 0){
            return 0;
        }
        for(high = 0; high < nums.size(); high++){
            sum += nums[high];
            while(sum > goal){
                sum -= nums[low];
                low++;
            }
            if(sum <= goal){
                count+=high - low + 1; //high se low ke beech saari subarrays
            }
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //exact k = atmost k - atmost (k-1)
        return atmostSubArray(nums, goal) - atmostSubArray(nums, goal - 1);
    }
};