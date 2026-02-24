class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i<nums.size()-2; i++){
            //to make it triple end ke 2 box chodhne hi padenge hence -2

            //also skip duplicate of i 
            if(i>0 && nums[i] == nums[i-1]) continue;

            int left = i+1; 
            int right = nums.size() -1 ;
            int sumTarget = -1 * nums[i];
            while(left<right){

                // left + right + i = 0
                // left + right = - i and hence converted to two sum
                
                int s = nums[left]+nums[right];

                if(s == sumTarget){
                    //apply 2 sum with duplicates
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    //now handle duplicates
                    while(left<nums.size() && nums[left]==nums[left-1]){
                        left++;
                    }
                    while(right>=0 && nums[right]==nums[right+1]){
                        right--;
                    }
                }else if( s< sumTarget  ){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return ans;
    }
};