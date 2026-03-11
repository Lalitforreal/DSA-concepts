//LC 452

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>> ans;

        int start1 = points[0][0];
        int end1 = points[0][1];
        for(int i = 1; i < points.size(); i++){
            int start2 = points[i][0];
            int end2 = points[i][1];
            if(end1>= start2){
                start1 = start1;
                end1 = min(end1,end2); //min cause shooting range is max(s1,s2) -- min(e1,e2) or basically the intersection
                continue;
            }
            ans.push_back({start1,end1});
            start1 = start2;
            end1 = end2;
        }
        ans.push_back({start1,end1});
        return ans.size();//Each group of overlapping balloons can be burst with one arrow.

    }
};