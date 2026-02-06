//find triplets in array whose sum is 0 



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

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == 0) {
                found = true;
                break;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
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