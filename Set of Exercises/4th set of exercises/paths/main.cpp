#include <iostream>
using namespace std;
int main() {
    int n,m,start,end,paths[2];
    int *a=new int [100000000];
    cin>>n>>m;
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            a[i*n+j]=0;
    for(int i=0;i<m;++i){
        cin>>start>>end;
        if(start<end){
            a[start*n+end]++;
        }else if(start>end) a[end*n+start]++;
    }
    int answer,sum,counter=0;
    for(int i=0;i<n;++i){
        sum=0;
        for(int j=i+1;j<n;++j){
                sum+=a[i*n+j]; }
        for(int j=0;j<i;++j){
            sum+=a[j*n+i];
        }
        if(sum%2!=0 && counter<2){
            paths[counter]=i;
            ++counter;}else if(sum%2!=0) counter++;
    }
    if(counter==0) answer=1;
    else if(counter==2) answer=2;
    else answer=0;

    if(answer==2){
        if(paths[0]<paths[1])
            cout<<"PATH "<<paths[0]<<" "<<paths[1]<<endl;
        else
            cout<<"PATH "<<paths[1]<<" "<<paths[0]<<endl;
        return 0;
    }
    else if(answer==1){
        cout<<"CYCLE"<<endl;
        return 0;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
