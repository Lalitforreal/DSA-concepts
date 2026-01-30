#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector <int> v(2,100); //{100, 100}
    v.insert(v.begin(), 300); // insert(at what posn, what data to insert)
    for(auto it : v){
        cout<< it << ", ";
    }
    return 0;

}