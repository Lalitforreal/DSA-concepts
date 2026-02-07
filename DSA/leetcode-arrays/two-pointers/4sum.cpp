class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());


        if(nums.size() <4)return ans;

        for(int i = 0 ; i < nums.size() - 3 ; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j = i+1; j<nums.size()-2; j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1;
                int right = nums.size() -1;
                long long sumTarget = (long long)target - nums[i] - nums[j];
                while(left<right){
                    long long sum = nums[left] + nums[right];
                    if(sum == sumTarget){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        //handle duplicate
                        while(left<right && nums[left] == nums[left -1]){
                            left++;
                        }

                        while(left<right && nums[right] == nums[right + 1]){
                            right--;
                        }
                        
                    }
                    else if(sum<sumTarget){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};