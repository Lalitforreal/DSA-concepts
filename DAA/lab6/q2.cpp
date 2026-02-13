#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<pair<long long, long long>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    int count = 1;
    long long last_end = v[0].second;

    for (int i = 1; i < n; i++) {
        if (v[i].first >= last_end) {
            count++;
            last_end = v[i].second;
        }
    }

    cout << count;

    return 0;
}
