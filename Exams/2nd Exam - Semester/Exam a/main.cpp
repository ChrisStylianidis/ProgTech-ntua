#include <iostream>
#include <vector>
using namespace std;
void support(int u,int v,char check,int &Answer,
              const vector<char> &characters_array,const vector<int> a[]){
    int value=a[u][v];
    if(characters_array[value]!=check) return;
    for(int x=0; x<a[value].size();++x)
        if(characters_array[a[value][x]]==check)
            Answer++;
    }
int main() {
    vector<char> characters_array;
    int Answer=0,N,M;
    vector<int> a[100000];
    cin>>N>>M;
    char character;
    for(int i=0;i<N;++i){
        cin>>character;
        characters_array.push_back(character);}

    for(int i=0;i<M;++i){
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
    }
    for(int x=0;x<N;x++)
        for(int i=0;i<a[x].size();++i)
            support(x,i,characters_array[x],Answer,characters_array,a);
    cout<<Answer<<endl;
    /*
    for(int x=0;x<N;x++){
        cout<<characters_array[x]<<" "<<x<<":";
        for(int i=0;i<a[x].size();++i){
            cout<<" "<<a[x][i];
        }
        cout<<endl;
    }*/
    return 0;
}
