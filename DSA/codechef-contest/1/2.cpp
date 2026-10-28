//https://www.codechef.com/START262D/problems/RHYDOOR

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin>> T;
    while(T--){
        int N;
        string S; 
        cin>>N>>S;
        
        int count = 0;
        int openings = 0;
        char last = ' ';
        
        for(int i = 0; i < N; i++){
            if(S[i]== last){
                count++;
            }else{
                last = S[i];
                count = 1;
            }
            
            if(count == 3){
                openings++;
                count = 0;
                last = ' ';
            }
        }
        cout<< openings<<'\n';
    }
    return 0;
}
