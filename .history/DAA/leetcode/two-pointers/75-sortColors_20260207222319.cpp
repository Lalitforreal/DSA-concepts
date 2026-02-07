class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int i = 0;
        int right = nums.size()-1;

        while(i<=right){
            if(nums[i] == 2){
                swap(nums[i], nums[right]);
                //dont move i cause ydk what will it be swapped with
                right--;
            }else if(nums[i] == 0){
                swap(nums[i],nums[left]);
                //here you can move i as well cause 2 wouldve been moved already so onlypossible option is 1
                i++;
                left++;
            }else{
                i++;
            }
        }
    }
};