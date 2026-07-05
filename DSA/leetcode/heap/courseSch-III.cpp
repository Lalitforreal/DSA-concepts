//lc 630
// There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

// You will start on the 1st day and you cannot take two or more courses simultaneously.

// Return the maximum number of courses that you can take.

 

// Example 1:

// Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
// Output: 3
// Explanation: 
// There are totally 4 courses, but you can take 3 courses at most:
// First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
// Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
// Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
// The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.


class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>& a,const pair<int,int>& b){
            if(a.first!= b.first){
                return a.first > b.first;
            }
            return a.second > b.second;
        }
    };
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;
        priority_queue<int> pq2;
        for(auto i : courses){
            pq.push({i[1], i[0]});
        }

        int curr = 0;
        while(!pq.empty()){
            if(curr + pq.top().second <= pq.top().first){
                curr+=pq.top().second;
                pq2.push(pq.top().second);
                pq.pop();
            }else{
                if(!pq2.empty() && pq.top().second < pq2.top()){ //only replace if better(curr accepted max se chota ho)
                    //pop largest push current
                    curr -= pq2.top();
                    pq2.pop();

                    curr += pq.top().second;
                    pq2.push(pq.top().second);
                    pq.pop();
                }else{
                    //skip curr
                    pq.pop();
                }
            }
        }
        return pq2.size();

    }
};