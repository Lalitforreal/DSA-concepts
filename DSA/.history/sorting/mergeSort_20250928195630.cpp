#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& arr, int low, int high){
    //base case
    if(low == high){
        return;
    }
    int mid = (low+high)/2;

    mergeSort(arr, low, mid );
    mergeSort(arr, mid+1, high);
    merge(arr,low,mid,high);
}


void merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    //when left/right is exhaused
    while(left<= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    //add to array
    for(int i = low; i<=high; i++){
        arr[i] = temp[i-low];
    }
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