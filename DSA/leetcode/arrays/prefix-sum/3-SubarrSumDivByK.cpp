//lc 974

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> f; //stores remainder -> freq
        int sum = 0; 
        f[0] = 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum+=nums[i];
            int rem = sum % k;
            if(rem < 0){
                rem = rem + k;
            }
            //if we have seen remainder before we increment, as eg 2 prefix are 4 adn 9 so 
            // diff = 9 - 4 = 5 and 5% 5 = 0 hence divisible 
            //remainders match will guarentee is divisible by k
            //All previous prefixes with this remainder create valid subarrays ending here.
            ans += f[rem];

            //update map
            f[rem]++;

        }
        return ans;

    }
};