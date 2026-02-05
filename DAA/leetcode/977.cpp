class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int left = 0;
        int n = nums.size();
        int right = n; //edge case when all negative(assume) else if right =-0 toh all postive

        for(int i = 0 ; i< nums.size(); i++){
            if(nums[i]>=0){
                right = i;
                break;
            }
        }
        left = right -1;
        // cout<<left<<" "<<right;

        //if never moved hence all positive
        if(right == 0){
            for(int i = 0 ; i<nums.size();i++){
                nums[i]=nums[i]*nums[i];
            }
            return nums;
        }

        //all negative
        if(right == n){
            for(int i = 0 ; i<nums.size();i++){
                nums[i]=nums[i]*nums[i];
            }
            reverse(nums.begin(),nums.end());
            return nums;
        }

        while(left>=0 && right<=nums.size()-1){
            if(abs(nums[left])>abs(nums[right])){
                result.push_back(nums[right]*nums[right]);
                right++;
            }else if(abs(nums[left]) == abs(nums[right])){
                result.push_back(nums[right]*nums[right]);
                right++;
            }else if(abs(nums[left]) < abs(nums[right])){
                result.push_back(nums[left]*nums[left]);
                left--;
            }else{
                continue;
            }

        }

            //leftovers outside the while
            while(left>=0){
                result.push_back(nums[left]*nums[left]);
                left--;
            }
            while(right<=nums.size()-1){
                    result.push_back(nums[right]*nums[right]);
                    right++;          
            }
        return result;

    }
};