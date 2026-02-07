//approach 1
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //no inplace needed so just construct sign arrays and merge them accordingly 

        vector<int> pos;
        vector<int> neg;
        for(int i =0; i<nums.size(); i++){
            if(nums[i]>=0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
            }
        }
            int left = 0;
            int right = 0;
        for(int i = 0; i<nums.size();i++){

            if(i % 2 == 0){//even
                nums[i] = pos[left];
                left++;
            }else{
                nums[i]=neg[right];
                right++;
            }
        }

        return nums;
    }
};


//approach 2

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        int neg = 1;
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            if(nums[i]>=0){
                ans[pos] = nums[i];
                pos+=2;
            }else{
                ans[neg] = nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};