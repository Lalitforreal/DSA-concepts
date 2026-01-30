#include <iostream>
#include <vector>
#include <algorithm> //for swap
using namespace std;

void selection_sort(int arr[], int n) {
    for (int i=0; i <= n-2 ; i++) {
        int min_index = i;
        for(int j = i+1; j <= n-1; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}


void bubbleSort(vector<int>& arr){
    int n = arr.size();
    bool swapped;
    for(int i = 0; i<n-1; i++){
        swapped = false;

        //last element is already in place
        for(int j = 0; j< n- i -1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped= true;
            }
        }
        //if no swawp array is already sorted
        if(!swapped){
            break;
        }
    }
}

void insertionSort(vector<int>& arr){
    for(int i = 0; i< arr.size() - 1; i++){
        for(int j = i+1; j>0; j--){
            if(arr[j-1]>arr[j]){
                swap(arr[j-1],arr[j]);
            }else{
                break;
            }
        }
    }
}

int main(){

    int[] arr = new int[];
    arr = {5,2,4,1,3};

    selection_sort(arr);
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" , ";

    }
    return 0;
}