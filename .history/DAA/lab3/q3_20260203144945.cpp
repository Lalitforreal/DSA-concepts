#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, target;
    cout << "Enter number of elements=";
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number=";
    cin >> target;

    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (arr[i] + arr[j] + arr[k] + arr[l] == target) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) break;
        }
        if (found) break;
    }

    if (found) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}