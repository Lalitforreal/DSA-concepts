class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m -1;
        int right = n -1;
        int last = m+n-1;

        while(right>=0){
            if(left<0){
                //in case of 456000 and 123 when 456456 and last is at 
                //nums[2] left is negative and last will have to move behind to
                // put the right value into left
                nums1[last] = nums2[right];
                last--;
                right--;
            }else if(nums1[left] > nums2[right]){ //you have to check left first
                nums1[last] = nums1[left];
                last-- ;
                left-- ;
            }else{
                nums1[last] = nums2[right];
                last--;
                right--;
            }
        }
    }
};