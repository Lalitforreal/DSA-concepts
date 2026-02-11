//gfg

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int low = 0;
        int high = k -1;
        int n = arr.size();
        int sum = 0;
        int res = 0;
        
        for(int i = low; i<=high; i++){
            sum = sum + arr[i];
        };//window ka sum
        
        while(high < n){
            res = max(res,sum);
            low++; //low-1 ko subtract
            high++; //sum me jo already aage badh gaya hai high usko add
             sum = sum - arr[low-1];
             //check if high out of bounds / edge case if high at last
             if(high == n){
                 break;
             }
             //now add high
             sum = sum + arr[high];
        }
        return res;
        
    }
};