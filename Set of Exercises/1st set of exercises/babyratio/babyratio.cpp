//babyratio.cpp
#ifndef CONTEST
#include "babyratio.hpp"
#endif // CONTEST
#include<iostream>

using namespace std;
int rational::gcd(int a,int b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
 }
rational::rational(int n,int d){
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
rational rational::add(rational r){
    int N=nom,D=den;
    rational result(D*r.nom+N*r.den,D*r.den);
    bool flag=false;
    if(result.nom<0&&result.den>0)
        flag=true;
    if(result.den<0 && result.nom>0)
        flag=true;
    int m=gcd(abs(result.nom),abs(result.den));
	result.nom/=m;
	result.den/=m;
    result.nom=abs(result.nom);
    result.den=abs(result.den);
    if(flag==true)
        result.nom=-result.nom;
	 return result;
}
rational rational::sub(rational r){
    int N=nom,D=den;
    rational result(N*r.den-D*r.nom,D*r.den);
    bool flag=false;
    if(result.nom<0&&result.den>0)
        flag=true;
    if(result.den<0 && result.nom>0)
        flag=true;
    int m=gcd(abs(result.nom),abs(result.den));
	result.nom/=m;
	result.den/=m;
    result.nom=abs(result.nom);
    result.den=abs(result.den);
    if(flag)
        result.nom=-result.nom;
	 return result;
}
rational rational::mul(rational r){
    int x,y,g;
    x=r.nom*nom;
    y=r.den*den;
    g=gcd(x,y);
    x/=g;
    y/=g;
    if((x>0 && y<0)||(x<0 && y<0)){
        x=-x;
        y=-y;}
    return rational(x,y);
}

rational rational::div(rational r){
    int x,y,g;
    g=r.nom;
    r.nom=r.den;
    r.den=g;
    x=r.nom*nom;
    y=r.den*den;
    g=gcd(x,y);
    x/=g;
    y/=g;
    if((x>0 && y<0)||(x<0 && y<0)){
        x=-x;
        y=-y;}
    return rational(x,y);
}
void rational::print(){
	cout<<nom<<"/"<<den;
}
