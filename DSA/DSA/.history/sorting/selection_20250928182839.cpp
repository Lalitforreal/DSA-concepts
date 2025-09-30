#include <iostream>
#include <vector>
#include <algorithm> //for swap
using namespace std;

void selectionSort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i< n; i++){
        int last = n - i -1;
        int maxIndex = 0;

        //find max elem
        for(int j =1; j<= last ; j++){
            if(arr[j]> arr[maxIndex]){
                maxIndex = j;
            }
        }
        //put max elem at correfct position 
        swap(arr[maxIndex],arr[last]);

    }
}

int main(){
    vector<int> arr = {5,2,4,1,3};
    selectionSort(arr);
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" , ";

    }
    return 0;
}