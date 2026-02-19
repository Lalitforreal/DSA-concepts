#include <iostream>
using namespace std;

int partition(vector<int>& arr, int low,int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j<high; j++){
        if(arr[j]<= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
        //else j++ by the loop itself so dont have to worry about that
    }
    //outside the loop after it reached the pivot swap i and pivot
    swap(arr[i+1],arr[high]);
    return i+1; //returns the pivot jiske left me sab chote and right me usse bade
}


//dont pass by value, use reference
void quickSort(vector<int>& arr,int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);
    
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}

