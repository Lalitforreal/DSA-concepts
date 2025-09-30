#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector <int> v(2,100); //{100, 100}
    v.insert(v.begin(), 300); // insert(at what posn, what data to insert)
    //OP -> {300,100,100}
    for(auto it : v){
        cout<< it << ", ";
    } 
    return 0;

}