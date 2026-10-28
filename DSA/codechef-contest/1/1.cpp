//https://www.codechef.com/START262D/problems/ALARMM

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin >> T;
    while(T--){
        int N,K;
        string S;
        cin >> N >> K>> S;
        int alarms = 0;
        int coveredUntil = 0;
        
        for(int i = 0; i < N; i++){
            int room = i + 1;
            if(S[i] == '1' && room > coveredUntil){
                alarms++;
                coveredUntil = min(N, room +K);
            }
        }
        cout << alarms<< '\n';
    }
    return 0;
}
