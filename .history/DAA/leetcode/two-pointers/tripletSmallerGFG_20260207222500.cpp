//triplets with smaller sum 
class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        
        sort(arr,arr+n);//pointers instead of index
        
        int count = 0;
        
        for(int i = 0; i< n -2 ; i++){
            int left = i+1;
            int right = n-1;
            
            while(left<right){
                int sumT = arr[i]+arr[left]+arr[right];
                
                if(sum > sumT){
                    count+=(right-left); //if -2(i) and(0+3) < sum to (0+1) bhi kam hoga
                    left++;
                }
                else{
                    right--;
                }
                
            }
        }
        return count;
    }
};