class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        int n = nums2.size();

        for(int i = n-1; i >= 0; i-- ){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }

            if(st.empty()){
                mp[nums2[i]] = -1;
            }else{
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> res;
        for(int i = 0; i < nums1.size();i++){
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};


//or
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> monoSt;

        for(int i = nums2.size() - 1; i >= 0 ; i--){
            if(monoSt.empty()){
                mp[nums2[i]] = -1;
                monoSt.push(nums2[i]);
            }else{
                //not empty 
                //maintain a monotonically decreasing stack 
                if(monoSt.top() > nums2[i]){
                    mp[nums2[i]] = monoSt.top();
                    monoSt.push(nums2[i]);
                }else{
                    while(!monoSt.empty() && nums2[i] >= monoSt.top()){
                        monoSt.pop();

                    }
                    if(!monoSt.empty()){
                        mp[nums2[i]] = monoSt.top();
                        monoSt.push(nums2[i]);  
                    }else{
                        //stack empty 
                        mp[nums2[i]] = -1;
                        monoSt.push(nums2[i]);
                    }
                }
            }
        }


        //now use the map
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(mp[nums1[i]]);
        }

        return ans;


    }
};