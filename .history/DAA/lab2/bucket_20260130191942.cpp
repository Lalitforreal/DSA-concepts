#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<double> arr(n);

    cout << "Enter elements (range [0,1]):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        // Error handling
        if (arr[i] < 0.0 || arr[i] > 1.0) {
            cout << "Error: Negative value or value greater than 1 is not allowed.";
            return 0;
        }
    }

    // Step 1: Create n empty buckets
    vector<vector<double>> buckets(n);

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];   // bucket index
        if (index == n) index = n - 1; // edge case when value = 1
        buckets[index].push_back(arr[i]);
    }

    // Step 3: Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Step 4: Concatenate buckets
    cout << "Sorted elements:\n";
    for (int i = 0; i < n; i++) {
        for (double val : buckets[i]) {
            cout << val << endl;
        }
    }

    return 0;
}