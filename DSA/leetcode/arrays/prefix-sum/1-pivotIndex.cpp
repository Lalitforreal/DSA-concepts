//LC 724

//BRUTE
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //suffix index sum should be equal to prefix
        //create two array for prefix suffix and then compare both and if value is equal at any index return
        vector<int> prefix(nums.size(),0);
        vector<int> suffix(nums.size(),0);

        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i-1] + nums[i - 1];
        }

        int n = nums.size();
        for(int i = n - 2; i >=0; i-- ){
            suffix[i] = suffix[i+1] + nums[i+1];
        }

        //compare
        for(int i = 0; i < n; i++){
            if(prefix[i] == suffix[i]){
                return i;
            }else{
                continue;
            }
        }
        return -1;
    }
};

//optimised

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++){
            totalSum += nums[i];
        }

        for(int i = 0; i < nums.size(); i++){
            //totalSum = left + a[i] + right (left - prefixSum and right is suffix)
            int right = totalSum - left - nums[i];
            if(left == right){
                return i;
            }
            //make sure you calculate prefix in the end;
            left+=nums[i];
        }
        return -1;
    }
};