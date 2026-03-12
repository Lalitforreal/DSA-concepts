//GFG

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int room = 0;
        int res = 0;
        
        int i = 0;
        int j = 0;
        int n = start.size(); //cause after the last check in hi end ka check in hoga
        
        while( i < n && j < n){
            if(start[i] < end[j]){
                room ++;
                res = max(res, room);
                i++;
            }else{
                //even if equal consider room check out
                room--;
                j++;
            }
        }
        return res;
    }
};
