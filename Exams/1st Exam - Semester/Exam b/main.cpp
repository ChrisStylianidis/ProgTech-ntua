#include <iostream>
#include <list>
#include <string>
using namespace std;
void print_list(list<int> l){
    list <int>::iterator i,enamprosta=l.begin();
    enamprosta++;
    for(i=l.begin();enamprosta!=l.end();++i){
        cout<<*i<<" ";
        enamprosta++;
    }
    cout<<*i;
    cout<<endl;
}int main() {
    list<int> queue,stack;
    int N,s;
    string ent;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>s;
        queue.push_back(s);
    }
    cin>>ent;
    for(int i=0;i<ent.size();i++){
        if(ent[i]=='Q'){
            if(queue.empty()){
                cout<<"error"<<endl;
                return 0;
            }
            int kratumeno=queue.front();
            queue.pop_front();
            stack.push_front(kratumeno);
        }
        else if(ent[i]=='S'){
            if(stack.empty()){
                cout<<"error"<<endl;
                return 0;
            }
            int kratumeno=stack.front();
            stack.pop_front();
            queue.push_back(kratumeno);

        }else{
            print_list(queue);
        }
    }

    return 0;
}