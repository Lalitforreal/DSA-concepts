//brute force ->
//push the new INterval and sort so n log n 

//optimised
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //optimised, already sorted so we can do something with it
        vector<vector<int>> res;

        int p2 = newInterval[0];
        int s2 = newInterval[1];

        if(intervals.size() == 0){
            res.push_back({p2, s2});
            return res;
        }

        

        
        int count = 0;
        bool inserted = false;
        for(int i = 0; i < intervals.size() ; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(!inserted && p2 <= start){
                res.push_back({p2,s2});
                inserted = true;
            }

            res.push_back({start, end});
        }

        if(!inserted){
            res.push_back({p2,s2});
        }
        
        // //add remaining intervals into res
        // while(count < intervals.size() ){
        //     s1 = intervals[count][0];
        //     e1 = intervals[count][1];
        //     res.push_back({s1,e1});
        //     count++;
        // }


        for(int i = 0; i < res.size(); i++){
            cout << "[" << res[i][0] << "," << res[i][1] << "] ";
        }
        cout << endl;




        vector<vector<int>> ans;
        if(res.size() == 0){
            return res;
        }else{
            int start1 = res[0][0];
            int end1 = res[0][1];
            for(int i = 1; i < res.size(); i++){
                int start2 = res[i][0];
                int end2 = res[i][1];
                if(end1 >= start2){//merge
                    start1 = min(start1,start2);
                    end1 = max(end1,end2);
                    continue;
                }//if normal
                // after merge its normal so pushback
                ans.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
            //last elem is unique so push 
            ans.push_back({start1, end1});
            return ans;
        }
    }
};


//best one pass
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //in a single pass 
        //insert intervals while intervals.start < newIntervalStart
        //now merge those intervals
        //then insert the newInterval
        //add remaining
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();
        
        int start = newInterval[0];
        int end = newInterval[1];

        //firstly add the already sorted intervals until the intervalStart < newInt start
        //this is for teh intervals that are completely before the newInt
        
        while( i < n && intervals[i][1] < start){
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        //now compare and merge the overlapping newInterval with intervals if overlapping
        while( i < n && end >= intervals[i][0]){
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        //now push teh merged interval that we kept merging in the upper loop
        ans.push_back({start, end});

        //add remaining intervals
        while( i < n ){
            ans.push_back({intervals[i]});
            i++;
        }
        return ans;

    }
};