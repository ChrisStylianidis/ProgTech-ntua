//babyratiotest.cpp
#include<iostream>
#include "babyratio.hpp"
#include "babyratio.cpp"
using namespace std;


int main (){

rational a(2, 3);
rational b(12, 7);
a.mul(b).print();
cout<<" should be 8/7"<<endl;
rational c(3, 8);
rational d(-2, 11);
c.div(d).print();
cout <<" should be -33/16"<< endl;
return 0;}
