//LC 904

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int high = 0;
        unordered_map<int,int> f;
        int result = INT_MIN;

        for(high; high < fruits.size();high++){
            f[fruits[high]]++;
            while(f.size()>2){
                f[fruits[low]]--;
                low++;
                if(f[fruits[low-1]]== 0){
                    f.erase(fruits[low-1]);
                }
            }
            
            if(f.size() <=2 ){
                int len = high - low + 1;
                result = max(result, len);
            }


        }
        return result ;
    }
};