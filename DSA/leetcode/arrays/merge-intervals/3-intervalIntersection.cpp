//LC 986

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;

        if( firstList.size() == 0 || secondList.size() == 0){
            return ans;
        }

        int i = 0;
        int j = 0;

        while(i < firstList.size() && j < secondList.size()){
            //check intersection 
            // if yes then move the lower
            int s1 = firstList[i][0];
            int e1 = firstList[i][1];

            int p1 = secondList[j][0];
            int q1 = secondList[j][1];

            int maxStart = max(s1,p1);
            int minEnd = min(e1,q1);

            if(maxStart <= minEnd){
                ans.push_back({maxStart, minEnd});
            }

            if(e1 <= q1){//the one who ends first will not be in future intersection so move that 
            i++;

            }else{
                j++;
            }

        }
        return ans;
    }
};