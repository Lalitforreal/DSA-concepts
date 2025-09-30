#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector <int> v(5,100); //{100,100,100,100,100}

    // //insert single element
    // v.insert(v.begin(), 300); // insert(at what posn, what data to insert)
    // //OP -> {300,100,100}
    // for(auto it : v){
    //     cout<< it << ", ";
    // } 
    

    //insert 400 more than once in a location 
    v.insert(v.begin(),2, 400); //insert(where to insert, how many data(here no. of 400), data)
    for(auto it : v){
        cout<<it<<", ";
    }
    return 0;


}