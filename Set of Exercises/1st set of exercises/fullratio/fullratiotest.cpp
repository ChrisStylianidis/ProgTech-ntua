//fullratiotest.cpp
#include <iostream>
#include "fullratio.hpp"
#include "fullratio.cpp"
using namespace std;

int main() {
rational a(2, 3);
rational b(12, 7);
cout<<a*b<<" should be 8/7"<<endl;
rational c(3, 8);
rational d(-2, 11);
cout <<c/d<<" should be -33/16"<< endl;
return 0;
}
