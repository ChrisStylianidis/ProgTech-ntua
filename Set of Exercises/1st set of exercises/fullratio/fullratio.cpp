//fullratio.cpp
#include <iostream>
#ifndef CONTEST
#include "fullratio.hpp"
#endif

using namespace std;
int rational::gcd(int a,int b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
 }

rational::rational(int n, int d) {
	nom=n;
    den=d;
    bool flag=false;
    if(nom<0&&den>0)
        flag=true;
    if(den<0 && nom>0)
        flag=true;
    int m=gcd(abs(nom),abs(den));
    nom=nom/m;
    den=den/m;
    nom=abs(nom);
    den=abs(den);
    if(flag==true)
        nom*=-1;

}

rational operator + (const rational &x, const rational &y) {

    rational result(x.den*y.nom+x.nom*y.den,x.den*y.den);
    bool flag=false;
    if(result.nom<0 && result.den>0)
        flag=true;
    if(result.den<0 && result.nom>0)
        flag=true;
    int m=rational::gcd(abs(result.nom),abs(result.den));
	result.nom/=m;
	result.den/=m;
    result.nom=abs(result.nom);
    result.den=abs(result.den);
    if(flag==true)
        result.nom=-result.nom;
	 return result;
}

rational operator - (const rational &x, const rational &y) {
    int N=x.nom,D=x.den;
    rational result(N*y.den-D*y.nom,D*y.den);
    bool flag=false;
    if(result.nom<0&&result.den>0)
        flag=true;
    if(result.den<0 && result.nom>0)
        flag=true;
    int m=rational::gcd(abs(result.nom),abs(result.den));
	result.nom/=m;
	result.den/=m;
    result.nom=abs(result.nom);
    result.den=abs(result.den);
    if(flag)
        result.nom=-result.nom;
	 return result;
}
rational operator * (const rational &x,const rational &y){

    int a,b,g;
    a=x.nom*y.nom;
    b=x.den*y.den;
    g=rational::gcd(a,b);
    a/=g;
    b/=g;
    if((a>0 && b<0)||(a<0 && b<0)){
        a=-a;
        b=-b;}
    return rational(a,b);
}
rational operator / (const rational &x,const rational &y){

    int a,b,g;
    a=x.nom*y.den;
    b=x.den*y.nom;
    g=rational::gcd(a,b);
    a/=g;
    b/=g;
    if((a>0 && b<0)||(a<0 && b<0)){
        a=-a;
        b=-b;}
    return rational(a,b);
}
std::ostream & operator << (std::ostream &out, const rational &x){
cout<<x.nom<<"/"<<x.den;
return out;}

