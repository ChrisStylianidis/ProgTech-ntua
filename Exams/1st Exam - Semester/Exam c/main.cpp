#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
bool gramma(basic_string<char> a){
    return (a[0]>='a' && a[0]<='z')  ;
}
int unique(string a[],int siz){//afti edw i sinartisi itan lathos :(
    int result=0;
    bool again=false;
    for(int i=0;i<siz;++i){
        for(int j=i+1;j<siz;++j){
            if(a[i]==a[j]){
                again=true;
                break;}

        }
        if(!again) result++;
        again=false;
    }
    return result;
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

string maxword(string a[],int siz){
    int max=a[0].size();
    string dummy=a[0];
    for(int i=1;i<siz;++i){
        if(max<a[i].size()){
            dummy=a[i];
            max=a[i].size();
        }

    }
    return dummy;
}

string minword(string a[],int siz){
    int min=a[0].size();
    string dummy=a[0];
    for(int i=1;i<siz;++i){
        if(min>a[i].size()){
            dummy=a[i];
            min=a[i].size();
        }

    }
    return dummy;
}
int main() {
    map <char,vector<string>> dictionary;
    string a;
    while(!cin.eof()){//
        cin>>a;
        if(cin.eof()) break;
        if(a[0]>='a' && a[0]<='z'){
            dictionary[a[0]].push_back(a);
        }

    }
    int k;
    string *lekseis=new string[1000000];
    for(int i='a';i<='z';i++){
        if(dictionary[i].empty())continue;

        k=0;
        cout<<(char)i<<": "<<dictionary[i].size()<<" word(s), ";
            for(auto j=dictionary[i].begin();j!=dictionary[i].end();++j){
                lekseis[k]=*j;
                k++;
            }
        issessoso(lekseis,k);
        cout<<unique(lekseis,k)<<" unique word(s), longest \'";
        cout<<maxword(lekseis,k)<<"\' and shortest \'";
        cout<<minword(lekseis,k)<<"\'";
            cout<<endl;}

    return 0;
}
