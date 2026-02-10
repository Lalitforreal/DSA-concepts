#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

// Sort by value/weight ratio (descending)
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter value and weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;

    for (int i = 0; i < n && W > 0; i++) {
        if (items[i].weight <= W) {
            // Take whole item
            W -= items[i].weight;
            maxValue += items[i].value;
        } else {
            // Take fraction
            maxValue += items[i].value * ((double)W / items[i].weight);
            W = 0;
        }
    }

    cout << "Maximum Value: " << maxValue << endl;

    return 0;
}