class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int best = nums[0]+nums[1]+nums[2];

        for(int i = 0; i < nums.size()- 2 ; i++){
            int left = i+1;
            int right = nums.size()-1;

            while(left<right){
                int sum = nums[i]+ nums[left]+ nums[right];
                if(abs(sum - target) < abs(best - target)){
                    best = sum;
                }

                if(sum == target){
                    return sum;
                }
                if(sum < target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return best;
        
    }
};



// with max diff 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //keep the best sum and then compare if target-curr > taregt-best
        int maxDiff = INT_MAX;
        int resultSum = 0;
        
        sort(nums.begin(),nums.end());

        for(int i = 0; i<nums.size(); i++){

            int left = i+1;
            int right = nums.size() - 1;

            while(left<right){
                int total = nums[i] + nums[left]+nums[right];
                int diff = abs(target - total);
                if(maxDiff > diff){
                    maxDiff = diff;
                    resultSum = total;
                }
                //best case edge case
                if(total == target){
                    return resultSum;
                }

                if(total < target){
                    left++;
                }else{
                    right--;
                }

            }
        }
        return resultSum;
    }
};