#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void merge(vector<int>&arr, int low, int high,int mid){
    left = low;
    right = mid+1;

    //empty arr
    vector<int> tempArr;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            tempArr.push_back(arr[left]);
            left++;
        }else{
            tempArr.push_back(arr[right]);
            right++;
        }
    }

    //if leftovers on left or right
    while(left<=mid){
        tempArr.push_back(arr[left]);
        left++;
    }

    whiel(right<=high){
        tempArr.push_back(arr[right]);
        right++;
    }

    //now copy the new arr to the original 
    for(int i = low; i < high; i++){
        arr[i] = arr[i - low];
    }

}

void mergeSort(vector<int>& arr, int low, int high){
    //base case
    if(high == low){
        return;
    }

    int mid = (low+high)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low, high, mid);
}

int main(){
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};  // sample array
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array:   ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;

}