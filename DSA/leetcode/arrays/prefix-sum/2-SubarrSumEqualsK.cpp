//LC 560
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> f; //sum-k -> freq
        int sum = 0;
        int res = 0;
        //make empty subarr known to hashmap₹
        f[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            //total sum hai 
            sum+=nums[i]; 

            int ques = sum - k; //this is what the hashmap stores 
            int freq = f[ques]; // this freq is equivalent to the no. of times sum = k
            res += freq;
            //at end cause it should have prev sum when checking stuff above

            f[sum]++; //insert new prefix sum, if sum = k you gotta store it so you can check later
        }
        return res;
    }
};