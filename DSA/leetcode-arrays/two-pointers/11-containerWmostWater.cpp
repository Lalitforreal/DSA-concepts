class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size()-1;

        int maxArea = 0;

        while(low<=high){
            int length = min(height[low],height[high]);
            int breadth = high - low;
            int area = length * breadth;

            if(area > maxArea){
                maxArea = area;
            }

            if(height[low]< height[high]){
                low++;
            }else{
                high--;
            }
        }
        return maxArea;
    }
};