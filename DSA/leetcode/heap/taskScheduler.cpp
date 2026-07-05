//lc 621
// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
// Return the minimum number of CPU intervals required to complete all tasks.
// Example 1:
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
// After completing task A, you must wait two intervals before doing A again. The same applies to task B.
// In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        unordered_map<char, int> free;
        priority_queue<pair<int, char>> pq;

        for(int i = 0; i < tasks.size();i++){
            freq[tasks[i]]++;
            free[tasks[i]] = 1;
        }

        //iterate in map and create max heap acc to freq
        for(auto i : freq){
            pq.push({i.second, i.first});
        }

        vector<pair<int, char>> pulled;
        int seat = 1;
        while(!pq.empty()){
            //to check stuff
            while(!pq.empty()){
                
                pair<int, char> p = pq.top();
                pq.pop();
                if(free[p.second] <= seat){
                    if(p.first > 1){
                        pq.push({p.first -1, p.second});
                    }
                    free[p.second] = seat + n + 1;
                    break; //next from heap
                }else{
                    pulled.push_back(p);
                }
            }
            //end of check loop 
            for(auto i : pulled){
                pq.push(i);
            }
            pulled.clear();
            seat++;
        }
        return seat -1;
    }
};