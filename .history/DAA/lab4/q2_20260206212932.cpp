//sorted arr find a pair whose sum is equal to target


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    // Sort because input may NOT actually be sorted
    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    bool found = false;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            found = true;
            break;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    if (found)
        cout << "true";
    else
        cout << "false";

    return 0;
}