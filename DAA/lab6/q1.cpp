#include <bits/stdc++.h>
using namespace std;

long long maxProfit(int start[], int end[], long long profit[], int n){
    
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(end[i] > end[j]){
                swap(end[i], end[j]);
                swap(start[i], start[j]);
                swap(profit[i], profit[j]);
            }
        }
    }

    long long totalProfit = 0;
    long long lastEnd = 0;

    for(int i = 0; i < n; i++){
        if(start[i] >= lastEnd){
            totalProfit += profit[i];
            lastEnd = end[i];
        }
    }

    return totalProfit;
}

int main(){
    int n;
    cin >> n;

    int start[100];
    int end[100];
    long long profit[100];

    for(int i = 0; i < n; i++){
        cin >> start[i] >> end[i] >> profit[i];
    }

    cout << maxProfit(start, end, profit, n) << endl;
    return 0;
}