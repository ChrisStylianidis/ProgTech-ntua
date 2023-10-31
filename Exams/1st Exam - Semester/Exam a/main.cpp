#include <iostream>
#include <string>
#include <map>
using namespace std;

int Maxnum(int a[],int &n){
    int j=a[0],position=0;
    for(int i=1;i<n;i++)
        if(a[i]>j){
            j=a[i];
            position=i;}
    n=position;
    return j;
}

void issessoso(string A[],int N){
    int i,j;
    string temp;
    for(i=0; i<N; i++){
        temp=A[i];
        j=i-1;
        while(j>=0&&A[j]>temp){
            A[j+1]=A[j];
            j--;}
        A[j+1]=temp;}}

int main() {
    int D,N,loc;
    int *a=new int[100];
    for(int i=0;i<100;i++)
        a[i]=0;
    string word;
    map <int,string[1000]> m;
    bool again=false;
    cin>>N>>D;
    for(int i=0;i<N;i++){
        cin>>loc>>word;
        for(int j=0;j<a[loc]+1;j++)
            if(m[loc][a[j]]==word){
                again=true;
                break;
            }
        if(again==false){
        m[loc][a[loc]]=word;
        a[loc]++;}
        else{again=false; continue;}
    }

    /*
    for(int i=1;i<=D;i++){
        for(int j=0;j<a[i];j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    cout<<"----------"<<endl;
    */
    bool nowords=false;
    int counter=0,c;
    string lista[100];
    string check;
    for(int i=0;i<a[1];i++){
        if(a[1]!=0){
        check=m[1][i];}
        else{nowords=true; break;}
        c=0;
        for(int j=2;j<=D;j++)
            for(int z=0;z<a[j];z++)
                if(m[j][z]==check){
                    c++;
                    continue;
                }
        if(c==D-1){lista[counter]=check; counter++;}
    }
    issessoso(lista,counter);
    int numleks=Maxnum(a,D);
    cout<<"largest dictionary is "<<D<<" with "<<numleks<<" word(s)"<<endl;
    if(nowords){
        cout<<"0 word(s) appear in all dictionaries"<<endl;
    }
    else{
        for(int i=0;i<counter;i++){cout<<lista[i]<<endl;}
        cout<<counter<<" word(s) appear in all dictionaries"<<endl;
    }
}
