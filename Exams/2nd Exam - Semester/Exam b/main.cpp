#include <iostream>
#include <vector>
using namespace std;
bool is_found(vector<int> a,int check){
    for(int i=0;i<a.size();++i){
        if(a[i]==check)
            return true;}
    return false;}
int main() {
    vector<int> integers;
    int answer=0;
    int N, M;
    int L, U;
    cin >> N >> M >> L >> U;
    for (int i = 0; i < N; ++i) {
        int readme;
        cin >> readme;
        integers.push_back(readme);
    }
    vector<int> *array=new vector<int>[10000];
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        if(integers[v]+integers[u]<=U){
        array[u].push_back(v);
        array[v].push_back(u);}
    }
    for(int u=0;u<N;u++)
        for(int v=0;v<array[u].size();++v) {
            int value=array[u][v],athrisma;
            for(int x: array[value]){
                athrisma=-1;
                if(is_found(array[x],u)){
                    athrisma+=1+integers[u]+integers[value]+integers[x];}
                if(athrisma>=L && athrisma<=U){
                    answer++;
                }
            }
        }
    cout<<answer/6<<endl;

return 0;}








