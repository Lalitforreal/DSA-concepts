
//lc 435

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        int count = 0;
        vector<vector<int>> ans;
        for(int i = 1; i < intervals.size(); i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if(end1 <= start2){
                start1 = start2;
                end1 = end2;
                continue;
            }else{
            //if overlap remove the one with the larget end
            // [[1,10],[2,3],[3,4]] dry run
            end1 = min(end1,end2);
            count++;

            }
        }
        return count;
        
    }
};