#include <iostream>
#include <vector>
using namespace std;

// Stable counting sort based on digit represented by exp
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Count occurrences of digits
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;  // llike if exp - 10 ya 100th place hai toh 129 toh 29/10 = 12 %10 = 2 toh digit mil gaya 
        count[digit]++;
    }

    // Prefix sum (cumulative count) turning count into positions
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (RIGHT to LEFT for stability)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        //count is now the positions
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

}

int main() {
    int n;
    cout << "Enter number of parcel IDs: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter 5-digit parcel IDs:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int passes;
    cout << "Enter number of passes required: ";
    cin >> passes; //3 digit - 4 digits whatever

    int exp = 1;  // 1 -> units, 10 -> tens, 100 -> hundreds ...

    for (int i = 1; i <= passes; i++) {
        countingSort(arr, exp);
        exp *= 10;
    }

    cout << "List after " << passes << " pass(es): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}