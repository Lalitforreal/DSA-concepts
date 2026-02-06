
//find two elemetn whose sum is equal to third

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    bool found = false;

    // Fix the third element arr[k]
    for (int k = n - 1; k >= 2; k--) {
        int i = 0, j = k - 1;

        while (i < j) {
            int sum = arr[i] + arr[j];

            if (sum == arr[k]) {
                found = true;
                break;
            } else if (sum < arr[k]) {
                i++;
            } else {
                j--;
            }
        }

        if (found) break;
    }

    if (found)
        cout << "true";
    else
        cout << "false";

    return 0;
}