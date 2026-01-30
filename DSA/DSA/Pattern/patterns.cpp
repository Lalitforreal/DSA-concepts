#include <iostream>
using namespace std;
int n;
// void pattern(int n){
//         for(int i = 1; i<= n; i++){
//         for(int j=1; j<=n - i +1; j++){
//             cout<< j;
//         }cout<<endl;
//     }
// }



void pattern(int n){
    for(int i = 0; i<=n; i++){
        //for space
        for(int j= 0; j<i; j++){
            cout<<" ";
        }
        //for stars
        for(int j = 0; j< 2*n - ((2*i) - 1 ); j++){
            cout<<"*";
        }
        //for space again 
        for(int j= 0; j<i; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
int main(){
    cin>> n;
    pattern(n);
}