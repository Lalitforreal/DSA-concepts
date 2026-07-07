//LC 258

class Solution {
public:
    int addDigits(int num) {
        if(num == 0){
            return 0;
        }
        if(num < 10) return num;
        int curr = num % 10;
        int remaining = num /10;
        return addDigits(curr + remaining);
    }
};