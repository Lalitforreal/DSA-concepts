//https://www.codechef.com/START262D/problems/EQLZR

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	
	while(T--){
	    int N;
	    cin >> N;
	    
	    vector<long long> A(N);
	    for(int i = 0; i < N; i++){
	        cin >> A[i];
	    }
	    
	    int score = 0;
	    
	    for(int i = 0; i < N - 1; i++){
	        if( A[i] == A[i+1]){
	            score++;
	        }
	    }
	    
	    int bestLeft = 0;
	    int ans = 0;
	    
	    for(int R = 0; R<N; R++){
	        int leftGain = 0;
	        
	        if(R>0){
	            if(A[R-1] == A[R] + 1){
	                
	                leftGain = 1;
	            }else if(A[R-1] == A[R]){
	                leftGain = -1;
	            }
	            
	            
	        }
	        
	        bestLeft = max(bestLeft, leftGain);
	        
	        int rightGains = 0;
	        
	        if(R < N - 1){
	            if(A[R+1] == A[R] + 1){
	                rightGains = 1;
	            }else if(A[R] == A[R+1]){
	                rightGains = -1;
	            }
	        }
	        
	        ans = max(ans, score+bestLeft+rightGains);
	    }
	    
	    cout << ans << '\n';
	}
	
	return 0;

}