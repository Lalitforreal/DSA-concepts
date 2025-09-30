#include <iostream>
using namespace std;
int main(){
    //how we declare a vector/ create an empty container
    vector <int> vec1;

    vec1.push_back(1); //this will add the int 1 in the empty container
    vec1.emplace_back(1); // this is the same as pushback but with a difference you"ll know next

    //you can define vector of a pair datatype too
    vector <pair<int, int>> vecPair;
    vecPair.push_back({1,2});
    //here comes the differencem here you dont have to use curly braces to differ, in emplace back it directly assumes its a pair
    vecPair.emplace_back(1,2);

    //if i wanna declare a vector where the elements already exist vvector_name(size, which element is it filled with)
    vector <int> v(5,100); //{100,100,100,100,100}
    ///what if you dont want the 100 inside you can also just decalare the size
    vector <int> v1(5);

    //to copy a vector into another
    vector <int> vector1(5,20);
    vector <int> vector2(v1);



    vector<int>::iterator it = v.begin(); //begin points at the start index of the vector

    //case 1 if vector us {2,10,15,20}
    it++;  //10 ko point karega it 
    cout<< *(it) << " "; //pointer * points to  to the memory location and print

    //case 2
    it+=2;
    cout<<*(it)<<" ";

    

}