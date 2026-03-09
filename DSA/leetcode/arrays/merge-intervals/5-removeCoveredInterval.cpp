//LC 1288

class Solution {
public:

    //in cases like [12,14],[12,34] you want the bigger a[1] before 
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]){
            return a[1] > b[1]; //larger end first
        }
        return a[0] < b[0];//smaller start first
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp); //pass compare fn

        int s1 = intervals[0][0];
        int e1 = intervals[0][1];
        int coveredCount = 0;
        for(int i = 1; i < intervals.size(); i++){
            int p1 = intervals[i][0];
            int q1 = intervals[i][1];

            if( p1 >= s1 && q1 <= e1 || p1 <= s1 && q1>=e1){
                coveredCount++;
                continue; //only the p and q moves
            }
            s1 = p1;
            e1 = q1;
        }
        return intervals.size()-coveredCount;
    }
};