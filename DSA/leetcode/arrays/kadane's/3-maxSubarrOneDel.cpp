//1186
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = INT_MIN;
        int ans = arr[0];

        int v1;

        for(int i = 1; i < arr.size(); i++){
            int prevNoD = noDelete;
            int prevD = oneDelete;

            noDelete = max(noDelete + arr[i], arr[i]);
            if(prevD == INT_MIN){//firstElem
                v1 = arr[i];
            }else{
                v1 = prevD + arr[i];
            }
            oneDelete = max(v1, prevNoD);

            ans = max(ans, max(noDelete, oneDelete));
        }
        return ans;
    }
};