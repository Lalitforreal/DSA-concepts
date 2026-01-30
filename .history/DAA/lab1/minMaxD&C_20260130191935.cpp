#include <iostream>
#include <vector>   
using namespace std;

struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(const vector<int>& arr, int low, int high) {
    MinMax result, left, right;

    // One element
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // Two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;

    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    MinMax ans = findMinMax(arr, 0, n - 1);

    cout << "Minimum element = " << ans.min << endl;
    cout << "Maximum element = " << ans.max << endl;

    return 0;
}