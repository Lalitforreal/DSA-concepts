#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector <int> v(2,100); //{100,100}

    // // //insert single element
    // v.insert(v.begin(), 300); // insert(at what posn, what data to insert)
    // //OP -> {300,100,100}
    // for(auto it : v){
    //     cout<< it << ", ";
    // } 
    

    // //insert 400 more than once in a location 
    // v.insert(v.begin(),2, 400); //insert(where to insert, how many data(here no. of 400), data)
    // for(auto it : v){
    //     cout<<it<<", "; //output -> {400,400,100,100}
    // }
    // return 0;


    //now if you want to insert an entire vector inside another

    vector <int> copy(2,100); //{50,50}
    v.insert(v.begin(), copy.begin(),copy.end()); 
    //insert(where in the dest. vec, start of vec you want to insert, end of ___)

    for(auto it = v.begin(); it != v.end(); it++){
        cout<< *it<< ", ";
    }
    return 0;



}